# Data Structures Implemetation
My own implemetation all most famous Data Structures using standard C.

| Data Structures | Based on Structures | Related Structures | Complexity | Check-List |
|-----------------|---------------------|--------------------|------------|------------|
| Stack           | Single Linked List  |                    |            |<ul><li>- [x] Done</li><li>- [x] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [x] Comments</li><ul>		   |
| Queue           | Dynamic Arrays      |                    |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
| Tree            | Queue               |                    |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
| Hash Map        | Dynamic Arrays      |                    |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
## Table of Content
- [Data Structures Implemetation](#data-structures-implemetation)
	- [Table of Content](#table-of-content)
	- [Installation](#installation)
		- [Prerequirements](#prerequirements)
		- [Install](#install)
	- [Stack](#stack)
	- [TODO](#todo)
## Installation
### Prerequirements
For the build creation from the sources, you will needed in CMake. This util will configure a project structure for any IDE. You can download it [here](https://cmake.org/download/).
### Install 
- Go to the path where you want to clone
	> \> cd <your_path\>
- Clone the repository
	> \> git clone https://github.com/JuiceFV/Data_Structures_Implemetation.git Data_Structures_Imlementation
- Go to the working derictory, which we have been cloned on previous step
	> \> cd Data_Structures_Imlementation
	- Now you have a such hierarchy
  
		![Working directory tree](https://user-images.githubusercontent.com/35202460/72209548-a4b65780-34c0-11ea-8fc7-8ce92447e345.png)
- Now let's create folder called "build"
	> \> mkdir build
- And going there
	> \> cd build
- Now, let's build the project for any IDE that you want
  - **If you woud like to pick another IDE**
	- You can check the list of the available IDE
		> \> cmake -G
	- Now you will see the list of IDE. You can see the star beside an IDE name, it's a current IDE and the build will be making for this IDE. You can pick any IDE, which you like by typing this command. You can find more information [here](https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html)
		> \> cmake -G <ide-name\> ..
	- The default build type is Release type, if you would like to pick the other type just use this command
		> \> cmake -G <ide-name\> -DCMAKE_BUILD_TYPE=Debug ..
  - **If the current IDE suit you**
    - Just use this command. And as in the previous step you can change the build type
		> \> cmake [optional: -DCMAKE_BUILD_TYPE=Debug] ..
- CMake will configure the project in the "build" and you can work with it.
## Stack
## TODO
- Optimize the code
