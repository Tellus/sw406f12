# Compiler command.
CC=g++
# Flags.
FLAGS=-Wall -std=c++0x
# Includes.
# INCS=-I. -ITrees -IErrorHandling -IParser -IToken -ICodeGeneration -ISymbolTables -IScanner
INCS=-I.
# Linker switches.
LIB=-L /usr/lib -lboost_regex
SOURCES= \
./Trees/assignmentnode.cpp \
./Trees/declarationnode.cpp \
./Trees/setnode.cpp \
./Trees/booleannode.cpp \
./Trees/numbernode.cpp \
./Trees/arithmeticnode.cpp \
./Trees/stringnode.cpp \
./Trees/valuekeynode.cpp \
./Trees/classmembernode.cpp \
./Trees/abstractsyntaxnode.cpp \
./Trees/conditionnode.cpp \
./Trees/callnode.cpp \
./Trees/programnode.cpp \
./Trees/referencekeynode.cpp \
./Trees/identifiernode.cpp \
./ErrorHandling/compileerror.cpp \
./program.cpp \
./Parser/parser.cpp \
./Token/token.cpp \
./CodeGeneration/generator.cpp \
./SymbolTables/symboltable.cpp \
./Scanner/scanner.cpp \
./Scanner/regexmanager.cpp \

# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)

U_OBJECTS=$(U_SOURCES:.cpp=.o)

OBJ_DIR=obj

EXECUTABLE=neocompiler

# Extension
EXT=.exe

all: init $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(U_OBJECTS)
	$(CC) $(INCS) $(LIB) $(OBJECTS) $(U_OBJECTS) -o $@

init:
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
    
clean:
	rm -rf $(OBJ_DIR)/*.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	if test -d $(OBJ_DIR); then rm -r $(OBJ_DIR); fi
	rm $(OBJECTS)
	
.cpp.o:
	$(CC) -c $(FLAGS) $(CFLAGS) $(INCS) $(LIB) $< -o $@
	
dev: all
	./$(EXECUTABLE)$(EXT)
