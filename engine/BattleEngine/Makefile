# Compiler command.
CC=g++
# Flags.
FLAGS=-ggdb -Wall -std=c++0x -ggdb
# Includes.
INCS=-I. -IHeaders
# Linker switches.
#LIB=
SOURCES= Source/Character/Ability.cpp Source/Character/Attribute.cpp Source/Character/Character.cpp Source/Character/ContEffect.cpp Source/Character/Resource.cpp Source/program.cpp Source/System/AbilityTable.cpp Source/System/Action.cpp Source/System/Behaviour.cpp Source/System/Effect.cpp Source/System/EventListener.cpp Source/System/GameState.cpp Source/System/RGRIdentifier/EnemyIdentifier.cpp Source/System/Team.cpp Source/Character/Primarch.cpp Source/System/RGRIdentifier.cpp Source/System/RGR_List.cpp Source/SexyAbility.cpp Source/AttackAbility.cpp Source/HealAbility.cpp Source/HealEffect.cpp Source/PhysicalDamageEffect.cpp Source/SexyEffect.cpp Source/PrettyPrinter.cpp Source/System/Exceptions/DuplicateKeyException.cpp Source/System/RGRIdentifier/OwnerIdentifier.cpp
# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)

OBJ_DIR=obj

EXECUTABLE=engine

# Extension
EXT=.exe

all: init $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCS) $(LIB) $(OBJECTS) -o $@

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
