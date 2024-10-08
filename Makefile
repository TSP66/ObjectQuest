# Compiler
CXX = g++

# Compiler flags
CXXFLAGS = -Wall -std=c++17

# Output executable name
TARGET = zooGame

# Source files
SRCS = main.cpp \
       Player.cpp \
       Tank.cpp \
       Zoo.cpp \
       LandEnclosure.cpp \
       Enclosure.cpp \
       Animal.cpp \
       LandAnimal.cpp \
       Information.cpp \
       AnimalInformation.cpp \
       EnclosureInformation.cpp \
       AquaticAnimal.cpp \
       AnimalMacros.cpp \
       Utilities.cpp \
       UtilitiesInformation.cpp \
       Bank.cpp \

# Header files
HDRS = Player.h \
       Tank.h \
       Zoo.h \
       LandEnclosure.h \
       Enclosure.h \
       Animal.h \
       game_logic.h \
       LandAnimal.h \
       AquaticAnimal.h \
       Information.h \
       AnimalInformation.h \
       EnclosureInformation.h \
       AnimalMacros.h \
       Utilities.h \
       UtilitiesInformation.h \
       Bank.h \
       

# Object files (automatically generated by replacing .cpp with .o)
OBJS = $(SRCS:.cpp=.o)

# Default target
all: $(TARGET)

# Link object files to create the executable
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(OBJS)

# Compile .cpp files into .o files
%.o: %.cpp $(HDRS)
	$(CXX) $(CXXFLAGS) -c $<

# Clean up object files and the executable
clean:
	rm -f $(OBJS) $(TARGET)

# Phony targets
.PHONY: all clean
