# Compiler command.
CC=g++
# Flags.
# FLAGS=-ggdb -Wall -std=c++0x
FLAGS=-Wall -std=c++0x
# Includes.
INCS=-I. -IHeaders -IUser/Headers
# Linker switches.
#LIB=-lboost_regex
LIB=-lboost_regex -lncurses
SOURCES = $(CHARACTER_OBJECTS) $(SYSTEM_OBJECTS) $(EXCEPTION_OBJECTS) \
Source/program.cpp \
Source/PrettyPrinter.cpp \
Source/SimpleWinCondition.cpp

CHARACTER_OBJECTS = \
Source/Character/Character.cpp \
Source/Character/Primarch.cpp \
Source/Character/Ability.cpp \
Source/Character/Attribute.cpp \
Source/Character/Resource.cpp \
Source/Character/EventCondition.cpp \

SYSTEM_OBJECTS = \
Source/System/RGRIdentifier.cpp \
Source/System/RGR_List.cpp \
Source/System/ActionDefinition.cpp \
Source/System/RGRIdentifier/TargetIdentifier.cpp \
Source/System/PrimarchIndexer.cpp \
Source/System/GameEvent.cpp \
Source/System/RGRIdentifier/OwnerIdentifier.cpp \
Source/System/RGRIdentifier/EnemyIdentifier_Unsafe.cpp \
Source/System/FullBehaviour.cpp \
Source/System/BehaviourRatio.cpp \
Source/System/Engine.cpp \
Source/System/WinCondition.cpp \
Source/System/AbilityTable.cpp \
Source/System/Action.cpp \
Source/System/Behaviour.cpp \
Source/System/Effect.cpp \
Source/System/EventListener.cpp \
Source/System/GameState.cpp \
Source/System/RGRIdentifier/EnemyIdentifier.cpp \
Source/System/Team.cpp

EXCEPTION_OBJECTS = \
Source/System/Exceptions/BaseException.cpp \
Source/System/Exceptions/DuplicateKeyException.cpp \
Source/System/Exceptions/PrimarchDoesNotExistException.cpp \
Source/System/Exceptions/NoValidActionException.cpp \
Source/System/Exceptions/EventLockedException.cpp \
Source/System/Exceptions/InvalidRGRException.cpp \
Source/System/Exceptions/NullParameterException.cpp \
Source/System/Exceptions/ResourceDoesNotExistException.cpp

U_SOURCES = \
User/Source/AttackAbility.cpp \
User/Source/HealAbility.cpp \
User/Source/HealEffect.cpp \
User/Source/PhysicalDamageEffect.cpp

# Object versions of sources.
OBJECTS=$(SOURCES:.cpp=.o)

U_OBJECTS=$(U_SOURCES:.cpp=.o)

OBJ_DIR=obj

EXECUTABLE=engine

# Extension
EXT=.exe

all: init $(SOURCES) $(EXECUTABLE)

$(EXECUTABLE): $(OBJECTS) $(U_OBJECTS)
	$(CC) -o $@ $(INCS) $(OBJECTS) $(U_OBJECTS) $(LIB) 

init:
	if test ! -d $(OBJ_DIR); then mkdir $(OBJ_DIR); fi
    
clean:
	rm -rf $(OBJ_DIR)/*.o
	if test -f $(EXECUTABLE)$(EXT); then rm $(EXECUTABLE)$(EXT); fi
	if test -d $(OBJ_DIR); then rm -r $(OBJ_DIR); fi
	rm $(OBJECTS)
	rm $(U_OBJECTS)
	
.cpp.o:
	$(CC) -c $< -o $@ $(FLAGS) $(INCS) $(LIB) 

eobjects: $(EXCEPTION_OBJECTS)
	$(CC) -c $< -o $@ $(FLAGS) $(INCS) $(LIB) 

dev: all
	./$(EXECUTABLE)$(EXT)
