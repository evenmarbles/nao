# CMake generated Testfile for 
# Source directory: /home/astrid/nao/projects/nao
# Build directory: /home/astrid/nao/projects/nao/build-linux64-naoqi-sdk
# 
# This file includes the relevent testing commands required for 
# testing this directory and lists subdirectories to be tested as well.
ADD_TEST(test_nao "/home/astrid/nao/projects/nao/build-linux64-naoqi-sdk/sdk/bin/test_nao")
SET_TESTS_PROPERTIES(test_nao PROPERTIES  TIMEOUT "20")
