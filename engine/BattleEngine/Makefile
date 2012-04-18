# Compiler command.
CC=g++
# Flags.
FLAGS=-c -Wall -std=c++0x
# Includes.
INCS=-I. -IHeaders
# Linker switches.
#LIB=
SOURCES= Source/Character/Ability.cpp Source/Character/Attribute.cpp Source/Character/Character.cpp Source/Character/ContEffect.cpp Source/Character/EffectDefinition.cpp Source/Character/Resource.cpp Source/program.cpp Source/System/AbilityTable.cpp Source/System/Action.cpp Source/System/Behaviour.cpp Source/System/Effect.cpp Source/System/EventListener.cpp Source/System/GameState.cpp Source/System/RGRIdentifier/EnemyIdentifier.cpp Source/System/Team.cpp
# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)

OBJ_DIR=obj

EXECUTABLE=engine

# Extension
EXT=

all: init $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCS) $(LIB) $(OBJECTS) -o $@

init:
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
	
clean:
	rm -rf $(OBJ_DIR)/*.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	if test -d $(OBJ_DIR); then rm -r $(OBJ_DIR); fi
	
.cpp.o:
	$(CC) $(FLAGS) $(INCS) $(LIB) $< -o $(OBJ_DIR)/$(@F)
	
dev: all
	./$(EXECUTABLE)$(EXT)
