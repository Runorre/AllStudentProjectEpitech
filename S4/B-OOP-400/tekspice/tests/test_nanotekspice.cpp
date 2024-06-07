/*
** EPITECH PROJECT, 2024
** B-OOP-400-MAR-4-1-tekspice-angelo.anselmet
** File description:
** test_nanotekspice
*/

#include <criterion/criterion.h>
#include <cstdlib>
#include <cstdio> 
#include <fstream> 

Test(nanotekspice, test1) {
    FILE* temp_file = fopen("tests/tmp/temp_or.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_1=0\nin_2=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/or.nts > tests/tmp/temp_or.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_or.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_or.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test2) {
    FILE* temp_file = fopen("tests/tmp/temp_and.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_1=0\nin_2=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/and.nts > tests/tmp/temp_and.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_and.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_and.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test3) {
    FILE* temp_file = fopen("tests/tmp/temp_xor.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_1=0\nin_2=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/xor.nts > tests/tmp/temp_xor.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_xor.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_xor.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test4) {
    FILE* temp_file = fopen("tests/tmp/temp_clock.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"cl=0\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/clock.nts > tests/tmp/temp_clock.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_clock.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_clock.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test5) {
    FILE* temp_file = fopen("tests/tmp/temp_counter.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"cl_clock=0\nin_reset=0\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4040_counter.nts > tests/tmp/temp_counter.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_counter.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_counter.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test6) {
    FILE* temp_file = fopen("tests/tmp/temp_4001.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_01=0\nin_02=1\nin_05=1\nin_06=1\nin_13=0\nin_12=0\nin_09=0\nin_08=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4001_nor.nts > tests/tmp/temp_4001.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_4001.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_4001.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test7) {
    FILE* temp_file = fopen("tests/tmp/temp_4001.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_01=0\nin_02=1\nin_05=1\nin_06=1\nin_13=0\nin_12=0\nin_09=0\nin_08=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4001_nor.nts > tests/tmp/temp_4001.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_4001.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_4001.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test8) {
    FILE* temp_file = fopen("tests/tmp/temp_4011.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_01=0\nin_02=1\nin_05=1\nin_06=1\nin_13=0\nin_12=0\nin_09=0\nin_08=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4011_nand.nts > tests/tmp/temp_4011.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_4011.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_4011.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test9) {
    FILE* temp_file = fopen("tests/tmp/temp_4071.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_01=0\nin_02=1\nin_05=1\nin_06=1\nin_13=0\nin_12=0\nin_09=0\nin_08=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4071_or.nts > tests/tmp/temp_4071.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_4071.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_4071.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}

Test(nanotekspice, test10) {
    FILE* temp_file = fopen("tests/tmp/temp_4081.txt", "w");
    if (!temp_file) {
        cr_assert_fail("Erreur : Impossible de créer le fichier temporaire");
    }
    fclose(temp_file);

    FILE* pipe = popen("echo \"in_01=0\nin_02=1\nin_05=1\nin_06=1\nin_13=0\nin_12=0\nin_09=0\nin_08=1\nsimulate\ndisplay\" | ./nanotekspice ./rsc/nts_single/4081_and.nts > tests/tmp/temp_4081.txt", "r");
    if (!pipe) {
        cr_assert_fail("Erreur : Impossible d'exécuter la commande");
    }
    pclose(pipe);

    std::ifstream temp_file_stream("tests/tmp/temp_4081.txt");
    if (!temp_file_stream.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier temporaire");
    }
    std::string output((std::istreambuf_iterator<char>(temp_file_stream)), std::istreambuf_iterator<char>());
    temp_file_stream.close();

    std::ifstream expected_file("tests/testfile/test_4081.txt");
    if (!expected_file.is_open()) {
        cr_assert_fail("Erreur : Impossible d'ouvrir le fichier attendu");
    }
    std::string expected_output((std::istreambuf_iterator<char>(expected_file)), std::istreambuf_iterator<char>());
    expected_file.close();

    cr_assert(output == expected_output, "Erreur : la sortie ne correspond pas au contenu du fichier attendu");
}