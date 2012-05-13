# Compiler command.
CC=g++
# Flags.
FLAGS=-ggdb -Wall -std=c++0x -ggdb
# Includes.
INCS=-I. -IHeaders -IUser/Headers
# Linker switches.
#LIB=
SOURCES= \
Source/Character/Ability.cpp \
Source/Character/Attribute.cpp \
Source/Character/Character.cpp \
Source/Character/ContEffect.cpp \
Source/Character/Resource.cpp \
Source/program.cpp \
Source/System/AbilityTable.cpp \
Source/System/Action.cpp \
Source/System/Behaviour.cpp \
Source/System/Effect.cpp \
Source/System/EventListener.cpp \
Source/System/GameState.cpp \
Source/System/RGRIdentifier/EnemyIdentifier.cpp \
Source/System/Team.cpp \
Source/Character/Primarch.cpp \
Source/System/RGRIdentifier.cpp \
Source/System/RGR_List.cpp \
Source/PrettyPrinter.cpp \
Source/System/Exceptions/DuplicateKeyException.cpp \
Source/System/RGRIdentifier/OwnerIdentifier.cpp \
Source/System/Exceptions/InvalidRGRException.cpp \
Source/System/Exceptions/NullParameterException.cpp \
Source/System/RGRIdentifier/EnemyIdentifier_Unsafe.cpp \
Source/System/Exceptions/ResourceDoesNotExistException.cpp \
Source/System/FullBehaviour.cpp \
Source/System/BehaviourRatio.cpp \
Source/System/BehaviourRatios/AttributeRatio.cpp \
Source/System/BehaviourRatios/ResourceRatio.cpp \
Source/System/Engine.cpp \
Source/System/WinCondition.cpp \
Source/SimpleWinCondition.cpp \
Source/System/PrimarchIndexer.cpp \
Source/System/Exceptions/PrimarchDoesNotExistException.cpp \
Source/System/Exceptions/NoValidActionException.cpp \
Source/System/Exceptions/EventLockedException.cpp \
Source/System/GameEvent.cpp \
Source/Character/EventCondition.cpp \
Source/System/ActionDefinition.cpp \
Source/System/RGRIdentifier/TargetIdentifier.cpp

U_SOURCES = \
User/Source/SexyAbility.cpp \
User/Source/AttackAbility.cpp \
User/Source/HealAbility.cpp \
User/Source/HealEffect.cpp \
User/Source/PhysicalDamageEffect.cpp \
User/Source/SexyEffect.cpp 
# User/Orc.cpp 

# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)

U_OBJECTS=$(U_SOURCES:.cpp=.o)

OBJ_DIR=obj

EXECUTABLE=engine

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
