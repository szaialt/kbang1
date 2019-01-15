TEMPLATE = subdirs
#@
#LD_LIBRARY_PATH=../src/
#@
#PROJECTS += ../src/kbang_common.pro ../src/kbang_client.pro

#SUBDIRS += ../src/kbang_common ../src/kbang_client
#kbang_common.file = ../kbang_common.pro
#kbang_client.file = ../kbang_client.pro

# Use ordered build, from first subdir (project_a) to the last (project_b):
CONFIG += ordered
