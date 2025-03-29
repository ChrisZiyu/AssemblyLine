# AssemblyLine
## 📌 Project Overview  
The **Assembly Line Management System** is a **C++-based simulation** of an **automated manufacturing process**.  
It efficiently processes customer orders through dynamically linked **workstations**, ensuring smooth order fulfillment.  


# 🚀 Assembly Line Management System (C++ Manufacturing Simulation)




## 🛠 Features  
- **Dynamic Assembly Line:** Workstations process orders in sequence.  
- **Flexible Configuration:** Allows reordering of stations for efficiency.  
- **File Handling:** Reads input data to load station details and orders.  
- **Order Fulfillment Tracking:** Maintains pending, completed, and incomplete orders.  
- **Exception Handling:** Prevents errors in workstation assignments and order flow.  

---

## 🏗 Project Modules  

### **1️⃣ CustomerOrder Module (`CustomerOrder.h` & `CustomerOrder.cpp`)**  
- Manages **customer orders**, including item requests and completion status.  
- Stores **order details**, such as item names and quantities.  
- Supports order **processing and fulfillment tracking**.  

### **2️⃣ Station Module (`Station.h` & `Station.cpp`)**  
- Represents a **single workstation** in the assembly line.  
- Maintains **inventory counts** and **dispenses items** to fulfill orders.  
- Reads **station data** from input files to set up the simulation.  

### **3️⃣ Workstation Module (`Workstation.h` & `Workstation.cpp`)**  
- Extends the **Station module** to support **customer order movement**.  
- Orders **progress through the workstation** if inventory allows.  
- Links to **next workstation dynamically** in the assembly line.  

### **4️⃣ LineManager Module (`LineManager.h` & `LineManager.cpp`)**  
- Oversees the **entire assembly line process**.  
- Ensures **orders move between workstations in the correct sequence**.  
- Supports **reordering of stations** for efficiency.  

### **5️⃣ Utilities Module (`Utilities.h` & `Utilities.cpp`)**  
- Provides helper functions for **string parsing and formatting**.  
- Handles **retrieval of tokens** from input data.  

### **6️⃣ Main Program (`ms1.cpp`, `ms3_prof.cpp`)**  
- **Entry point of the program** that initializes the simulation.  
- Loads **workstations, customer orders, and configurations** from files.  
- Runs the **assembly line process** in a loop.  

---

## 🚀 Installation & Setup  

### **Prerequisites**  
- C++ Compiler (e.g., **G++ or MSVC**)  
- C++ Standard Library (**STL**)  
- A terminal or IDE (e.g., **VS Code, Visual Studio, or CLion**)
- Set up Environment Variable as Stations1.txt Stations2.txt CustomerOrders.txt Assembly_Line.txt 

##🏆 Tech Stack
- Language: C++ (OOP, STL, File I/O)
- Data Structures: Vectors, Deques
- Concepts: Exception Handling, Debugging, Dynamic Object Management

---

## **📞 Contact**
📧 **Email:** [christianukiike@gmail.com](mailto:christianukiike@gmail.com)  
🔗 **GitHub:** [github.com/ChrisZiyu](https://github.com/ChrisZiyu)  

---

