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

EXECUTABLE=engine

# Extension
EXT=

all: $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS)
	$(CC) $(INCS) $(LIB) $(OBJECTS) -o $@
	
clean:
	rm -rf *.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	
.cpp.o:
	$(CC) $(FLAGS) $(INCS) $(LIB) $< -o $@
	
dev: all
	./$(EXECUTABLE)$(EXT)
