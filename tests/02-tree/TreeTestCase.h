//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include <boost/filesystem/path.hpp>
#include <fstream>

class TreeTestCase : public ::testing::Test {
public:
    TreeTestCase(){

        system("mkdir -p test_dir1/test_dir2/test_dir3");
        system("mkdir test_dir1/test_dir4");

        std::ofstream test_file1("test_dir1/test_dir4/test_file1.txt");
        test_file1 << "HERE WE GO AGAIN1";
        test_file1.close();

        std::ofstream test_file2("test_dir1/test_dir2/test_file2.txt");
        test_file2 << "HERE WE GO AGAIN2";
        test_file2.close();
    }

    virtual ~TreeTestCase(){
        remove("test_dir1/test_dir2/test_file2.txt");
        remove("test_dir1/test_dir4/test_file1.txt");

        rmdir("test_dir1/test_dir2/test_dir3");

        rmdir("test_dir1/test_dir4");
        rmdir("test_dir1/test_dir2");

        rmdir("test_dir1");
    }

};



