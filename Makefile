CXX = g++
CXXFLAGS = -std=c++11 -Wall
TARGET = RoomBookingSystem

SRC_DIR = src
INCLUDE_DIR = include
TEST_DIR = tests

all: $(TARGET)

$(TARGET): $(SRC_DIR)/RoomBookingSystem.cpp $(TEST_DIR)/test_RoomBookingSystem.cpp
	$(CXX) $(CXXFLAGS) -I $(INCLUDE_DIR) -o $(TARGET) $(SRC_DIR)/RoomBookingSystem.cpp $(TEST_DIR)/test_RoomBookingSystem.cpp

clean:
	rm -f $(TARGET)
