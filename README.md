# Course-Management-System (Hệ Thống Quản Lý Môn Học)


Chào mừng mọi người đã đến với project Hệ thống quản lý khoá học của nhóm mình! Dự án này được phát triển theo  yêu cầu của môn học và sử dụng ngôn ngữ C++, các thư viện GLFW, GLAD, OpenGL, và Dear ImGui. Trang README này sẽ hướng dẫn mọi người các bước để setup môi trường phát triển và chạy dự án.

Welcome to our Course Management System project! This project is developed as part of our class assignment and is built using C++, GLFW, GLAD, OpenGL, and Dear ImGui. This README will guide you through setting up your development environment and building the project.

## Team Members (Danh Sách Thành Viên)
- **Vương Gia Bảo** - MSSV: 23127002
- **Phạm Minh Triết** - MSSV: 23127132
- **Lê Trương Bảo Ngọc** - MSSV: 23127237
- **Bùi Thế Anh** - MSSV: 23127021

## Prerequisites (Công Cụ Cần Thiết)
Trước khi bắt đầu, hãy đảm bảo bạn đã cài đặt những công cụ sau:

Before you begin, ensure you have the following installed on your system:
- **Git**: Để quản lý phiên bản và làm việc với repo dự án (For version control and working with the project repository)
- **CMake**: Để build dự án (For generating build files)
- **Visual Studio Code**: IDE
- **C++ Compiler**

## Setting Up The Project (Cài Đặt Dự Án)
1. **Clone dự án (Clone the Repository)**
 
    `git clone --recursive https://github.com/HCMUS-CSC10002-Group-Project/Course-Management-System.git`


2. **Mở dự án bằng Visual Studio Code (Open the Project in Visual Studio Code)**

    Mở Visual Studio Code, `File -> Open Folder...` và chọn thư mục vừa clone về

    Launch Visual Studio Code, go to `File -> Open Folder...`, and select the project folder you just cloned

3. **Cài đặt các công cụ mở rộng (Install recommended extensions)**
 
    Để việc cài đặt dễ dàng hơn, bạn nên cài đặt các công cụ mở rộng cho VS Code sau:

    For an enhanced development experience, we recommend installing the following VS Code extensions:
    
    - C/C++ (by Microsoft)
    - CMake Tools (by Microsoft)

4. **Thiết lập dự án với CMake (Configure the Project with CMake)** 

    
    - Nhấn `Ctrl+Shift+P` để mở Command Palette (Press `Ctrl+Shift+P` to open the Command Palette)
    - Gõ `CMake: Configure` và nhấn Enter để thiết lập hệ thống build sử dụng CMake (Type `CMake: Configure` and press Enter. This sets up the build system using CMake)

5. **Build dự án (Build the Project)**

    - Mở Command Palette bằng `Ctrl+Shift+P` (Open the Command Palette with `Ctrl+Shift+P`)
    - Gõ `Cmake: Build` và nhấn Enter để compile dự án (Type `CMake: Build` and press Enter to compile the project.)

6. **Chạy dự án (Run the Application)**
    - Sau khi build xong, truy cập vào thư mục build vừa được tạo, chạy file .exe là xong (After building, navigate to the build directory, and run the compiled executable)