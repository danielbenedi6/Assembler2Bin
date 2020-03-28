#*****************************************************************
# File:   Makefile
# Author: Daniel Benedí García
# Date:   20 noviembre 2019
# Coms:   Execute 'make' to compile
#         Execute 'make clean' to delete generated files
#*****************************************************************

#---------------------------------------------------------
# macros
RM = /bin/rm -f  # to clean
CC = g++         # to compile
#---------------------------------------------------------
# vars
EJEC = assembler

TRANS_DIR 	= ./Translator
TRANS		= ${TRANS_DIR}/Translator

OBJECTS = ${TRANS}.o ${EJEC}.o

#---------------------------------------------------------
# to compile and link
CPPFLAGS = -g -I. -I${TRANS_DIR} -O2 -std=c++11
#---------------------------------------------------------

all: ${EJEC}
#---------------------------------------------------------
${EJEC}: ${OBJECTS}
	${CC} ${OBJECTS} -o ${EJEC} ${CPPFLAGS}
#---------------------------------------------------------
${EJEC}.o: ${EJEC}.cpp
	${CC} -c ${EJEC}.cpp ${CPPFLAGS}
#---------------------------------------------------------
${TRANS}.o: ${TRANS}.hpp ${TRANS}.cpp
	${CC} -c ${TRANS}.cpp -o ${TRANS}.o ${CPPFLAGS}

#---------------------------------------------------------
clean:
	${RM} ${OBJECTS} ${EJEC}
