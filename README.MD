# Data Structures Implemetation
This repository contains most famous Data Structures such as Stack, Queue, Tree, Hash Table etc. Due to I used different methods of implementation they might works a little bit slower. Also I tried to make something similar with C++ templates for the different types. For this purpose  I used ```#define``` macros and its operations, especially "##" (concatenation operation).

![Data Structures](https://media.geeksforgeeks.org/wp-content/uploads/20191010170332/Untitled-Diagram-183.png)

| Data Structures | Based on Structures | Related Structures | Complexity | Check-List |
|-----------------|---------------------|--------------------|------------|------------|
| Stack           | Single Linked List  | <ul><li> Vector</li><li> List</li><li> Some trees</li><ul>|<ul><li> Push: $\theta$(1)</li><li> Pop:  $\theta$(n)</li><li> Peek: $\theta$(1)</li><ul>            |<ul><li>- [x] Done</li><li>- [x] Memeory Leaks</li><li>- [x] Code optimization</li><li>- [x] Comments</li><ul>		   |
| Queue           | Dynamic Arrays      | <ul><li> Queue</li><li> Priority Queue</li><li> Some Trees</li><ul> |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
| Tree            | Queue/Stack               |                    |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
| Hash Map        | Dynamic Arrays      |                    |            |<ul><li>- [ ] Done</li><li>- [ ] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [ ] Comments</li><ul>		   |
## Table of Content
- [Data Structures Implemetation](#data-structures-implemetation)
	- [Table of Content](#table-of-content)
	- [Installation](#installation)
		- [Prerequirements](#prerequirements)
		- [Install](#install)
	- [Stack](#stack)
		- [Usage](#usage)
			- [Usage-Prerequirements](#usage-prerequirements)
			- [Methods](#methods)
			- [Errors and Undefined Behavior](#errors-and-undefined-behavior)
	- [How To Contribute](#how-to-contribute)
	- [Terms](#terms)
	- [Links](#links)
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
	- Now you have such hierarchy
  
		![Working directory tree](https://user-images.githubusercontent.com/35202460/72209548-a4b65780-34c0-11ea-8fc7-8ce92447e345.png)
- Create main.c in the current directory. Copy the code from the [Usage-Prerequirements](#usage-prerequirements) in your main.c according you compiler.
- Now let's create folder called "build"
	> \> mkdir build
- Going there
	> \> cd build
- Now, let's build the project for any IDE that you want
<details>
  <summary><b>If you woud like to pick another IDE</b></summary>
  <ul>
	<li> You can check the list of the available IDE </li>
		<blockquote>> cmake -G</blockquote>
	<li> Now you will see the list of IDE. You can see the star beside an IDE name, it's a current IDE and the build will be making for this IDE. You can pick any IDE, which you like by typing this command. You can find more information <a href ="https://cmake.org/cmake/help/v3.0/manual/cmake-generators.7.html">here</a></li>
		<blockquote>> cmake -G <ide-name\> ..</blockquote>
	<li> The default build type is Release type, if you would like to pick the other type just use this command</li>
		<blockquote>> cmake -G <ide-name\> -DCMAKE_BUILD_TYPE=Debug ..</blockquote>
   </ul>
</details>

<details>
<summary><b>If the current IDE suit you</b></summary>
    <ul><li> Just use this command. And as in the previous step you can change the build type</li>
		<blockquote>> cmake [optional: -DCMAKE_BUILD_TYPE=Debug] ..</blockquote>
	</ul>
</details>

- CMake will configure the project in the "build" and you can work with it.
## Stack
[Stack](https://en.wikipedia.org/wiki/Stack(abstract_data_type)) is a linear data structure in which elements are arranged in **LIFO (last in, first out)** order. It has two basic operations which are changes the stack, **push** and **pop**. Additionally it has **peek** operation. I implemented this structure using single-linked-list.

**push** - adds an element to the collection.

**pop** - removes the most recently added element that was not yet removed.

**peek** - gives access to the top without modifying the stack.

![Stack image](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

### Usage
#### Usage-Prerequirements
Before CMake's usage you will need to create the main.c file. There are two a little bit different implementation.
<details>
<summary><b>MSVS-Compiler</b></summary>

```c
#include "./includes/stack.h"
int main() {
  stack(int)* a = NULL;
  stack_constructor(int, a);
  /*
    Paste your code here
  */
  stack_destructor(a);
  return (0);
}
```
</details>
<details>
<summary><b>GNUC-Compiler</b></summary>

```c
#include "./includes/stack.h"
int main() {
  stack(int)* a = stack_constructor(int);
  /*
    Paste your code here
  */
  stack_destructor(a);
  return (0);
}
```
</details>

#### Methods
Basic stack-operations and their equivalent methods are listed here:

|Method name|Command in the my implementation|Complexity|
|-|-|-|
|**push** |```stack_push(stack, value)``` |$\theta$(1) |
|**pop** |```stack_pop(stack)``` |Basically, it's $\theta$(1) but in the my implementation it's $\theta$(n) due to single-linked-list usage|
|**peek** |```stack_peek(stack)``` |$\theta$(1)|
#### Errors and Undefined Behavior
* First, definition two or more objects (it doesn't works for the MSVC). I didn't check with GNUC but I'm promise I'ill check it.
```C
stack(int) *a = NULL;
stack(int) *b = NULL;
```
## How To Contribute
1. Clone repo and create a new branch:
   >\> git checkout https://github.com/JuiceFV/Data_Structures_Implemetation.git -b name_for_new_branch
2. Make changes and test
3. Submit Pull Request with comprehensive description of changes
## Terms
- ***Linear data structures*** - It is a data structure where elements are arranged in an orderly manner where the elements are attached adjacently. 
- ***Non-Linear data structures*** - It arranges the data in a sorted order and there exists a relationship between the data elements.
## Links
1. [Opaque pounters vs Macro templates](https://www.embedded.com/template-meta-programming-in-c-vs-opaque-pointer/)
2. [Templates onto C](https://habr.com/ru/post/154811/) (Russian lang.)
3. [Template queue using C](https://tiehu.is/blog/c1)
## TODO
- Queue Implementation
