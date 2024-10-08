# S50_MusthafaCP_OOP_SPACE_MISSION_SIMULATION

# Space Mission Control Simulation

## Project Overview

The **Space Mission Control Simulation** project is a C++ simulation that models the control and execution of a space mission. The simulation focuses on managing astronauts, spacecraft, mission objectives, and ground control operations. It offers a realistic portrayal of space mission management by simulating launch sequences, in-flight operations, and landing procedures.

## Features

1. **Spacecraft Launch and Landing**
   - Simulate the launch sequence of spacecraft.
   - Execute landing procedures for safe return to Earth.

2. **Astronaut Activities**
   - Manage astronaut activities, including Extravehicular Activities (EVAs) and scientific experiments.
   - Monitor astronaut health and task progress.

3. **Mission Control Operations**
   - Facilitate communication between mission control and spacecraft.
   - Monitor mission status and make real-time decisions.

4. **Resource Management**
   - Track and manage resources such as fuel, oxygen, and supplies.
   - Implement strategies for efficient resource utilization.

## Programming Language

The project is developed in **C++**, utilizing object-oriented programming principles to create a robust and flexible simulation environment.

## OOP Concepts Application

### Classes
- **Astronaut**: Represents an astronaut with attributes like name, role, and health status.
- **Spacecraft**: Models a spacecraft with attributes such as fuel level, capacity, and current mission status.
- **MissionControl**: Simulates mission control operations, including communication and decision-making.
- **GroundStation**: Represents a ground station responsible for monitoring and support.

### Objects
- Instantiate objects for each entity involved in the mission, such as astronauts, spacecraft, and ground stations.

### This Pointer
- Use the `this` pointer to reference the current object within class methods, allowing for access to instance variables and methods.

### Encapsulation
- Encapsulate data and methods within classes to ensure data integrity and provide controlled access.

### Inheritance
- Implement base classes for common attributes and behaviors.
- Derive specialized classes for different mission roles, such as Pilot, Engineer, and Scientist.

### Polymorphism
- Utilize polymorphic behaviors to handle different mission tasks and roles dynamically.
- Implement virtual functions to achieve runtime polymorphism.

### Abstraction
- Abstract common functionalities of mission control entities to simplify the design and improve maintainability.
