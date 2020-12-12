//
// Created by akhtyamovpavel on 5/1/20.
//


#include "TreeTestCase.h"
#include "Tree.h"

TEST_F(TreeTestCase, treeTestPathNotExistErr) {
    ASSERT_THROW(GetTree("somewhere", false), std::invalid_argument);
}

TEST_F(TreeTestCase, treeTestPathIsNotADirectoryErr) {
    ASSERT_THROW(GetTree("test_dir1/test_dir2/test_file2.txt", false), std::invalid_argument);
}


TEST_F(TreeTestCase, treeTest1) {
    FileNode testDir3Node {"test_dir3", true, {}};

    ASSERT_TRUE(GetTree("test_dir1/test_dir2/test_dir3", false) == testDir3Node);
    ASSERT_TRUE(GetTree("test_dir1/test_dir2/test_dir3", true) == testDir3Node);
}


TEST_F(TreeTestCase, treeTest2){
    FileNode testFileNode {"test_file1.txt", false, {}};

    FileNode testFileNodeParent {"test_dir4", true, {testFileNode}};
    FileNode testEmptyFileNodeParent {"test_dir4", true, {}};

    ASSERT_TRUE( GetTree("test_dir1/test_dir4", false) == testFileNodeParent);
    ASSERT_TRUE( GetTree("test_dir1/test_dir4", true) == testEmptyFileNodeParent);
}

TEST_F(TreeTestCase, treeTest3){
    FileNode testDir3Node {"test_dir3", true, {}};
    FileNode testFile2Node {"test_file2.txt", false, {}};

    FileNode testDir2NodeOnlyDir {"test_dir2", true, {testDir3Node}};
    FileNode testDir2NodeNotOnlyDir {"test_dir2", true, {testDir3Node, testFile2Node}};

    ASSERT_TRUE( GetTree("test_dir1/test_dir2", true) == testDir2NodeOnlyDir);
    ASSERT_TRUE( GetTree("test_dir1/test_dir2", false) == testDir2NodeNotOnlyDir);
}
