#!/usr/bin/python3

import sys
import os
import shutil
import subprocess

comp = "cc -Wall -Wextra -Werror -g {0} {1} -o {2}"

def get_executing_path():
    return os.path.dirname(os.path.abspath(sys.argv[0])) + '/'

def do_execution(exec_path, args):
    try:
        output = subprocess.check_output(f"{exec_path} {args}", shell=True, text=True, timeout=5, stderr=subprocess.STDOUT)
        return ("ok", output)
    except subprocess.TimeoutExpired as s:
        return ("timeout", s.output)
    except subprocess.CalledProcessError as s:
        return ("error", s.returncode)

def do_test(file_name, main, test_list):
    run_test = False
    if len(sys.argv) == 2 and sys.argv[1] == 'run_test':
        run_test = True

    if not run_test and not os.path.exists(get_executing_path() + file_name):
        print(f"Erreur: '{file_name}' n'existe pas")
        return False
    temp_path = get_executing_path() + 'test/'
    if os.path.exists(temp_path):
        shutil.rmtree(temp_path, ignore_errors=True)
    os.makedirs(temp_path)

    file_path = get_executing_path() + file_name
    ref_file_path = get_executing_path() + "../.answerz/" + file_name
    out_path = temp_path + 'out'
    ref_out_path = temp_path + 'ref'

    main_path = temp_path + 'main.c'
    if main != None:
        f = open(main_path, 'wt')
        f.write(main)
        f.close()

    print("Compilation...")
    if (os.system(comp.format(main_path if main != None else "", ref_file_path, ref_out_path))) != 0:
        print(f"Erreur: compilation du fichier de reference 'answer.c' echouee. Frappez la personne qui l'a ecrite")
        shutil.rmtree(temp_path, ignore_errors=True)
        return False
    if (not run_test and os.system(comp.format(main_path if main != None else "", file_path, out_path))) != 0:
        print(f"Erreur: compilation de '{file_name}' echouee :(")
        shutil.rmtree(temp_path, ignore_errors=True)
        return False
    
    print("Debut des tests...")
    if test_list == None:
        test_list = ['']
    for args in test_list:
        print(f"---- Test avec '{args}'... ", end='', flush=True)
        ref = do_execution(ref_out_path, args)
        if (ref[0] == "error"):
            print("OOPS\nLe programme de reference a plante. Ce n'est pas de votre faute. Vous etes legalement autorise a crier sur la personne qui l'a ecrite. Sortie:")
            if ref[1] == -11:
                print("Segmentation fault")
            else:
                print("Signal code:" + str(ref[1]))
            shutil.rmtree(temp_path, ignore_errors=True)
            return False
        elif ref[0] == "timeout":
            print("OOPS\nLe programme de reference a mis trop de temps a s'executer. Ce n'est pas de votre faute. Vous etes legalement "
                    + "autorise a crier sur la personne qui l'a ecrite. Sortie:")
            print(ref[1])
            shutil.rmtree(temp_path, ignore_errors=True)
            return False
        if run_test:
            print()
            print(ref[1])
            continue
        out = do_execution(out_path, args)
        if (out[0] == "error"):
            print("ERREUR\nVotre test a plante. Sortie:")
            if out[1] == -11:
                print("Segmentation fault")
            else:
                print("Signal code:" + str(out[1]))
            shutil.rmtree(temp_path, ignore_errors=True)
            return False
        elif out[0] == "timeout":
            print("ERREUR\nVotre test a mis trop de temps a s'executer. Cela est souvent du a une boucle infinie. Sortie:")
            print(out[1])
            shutil.rmtree(temp_path, ignore_errors=True)
            return False
        if ref[1] != out[1]:
            print("DIFF KO\n. Votre test n'est pas passe. Sortie attendue:")
            print(ref[1])
            print("Votre sortie:")
            print(out[1])
            shutil.rmtree(temp_path, ignore_errors=True)
            return False
        else:
            print("OK")
    print("Tous les tests passent !!")
    shutil.rmtree(temp_path, ignore_errors=True)

    return True
