# Data Structures Implemetation
This repository contains most famous Data Structures such as Stack, Queue, Tree, Hash Table etc. Due to I used different methods of implementation they might works a little bit slower. Also I tried to make something similar with C++ templates for the different types. For this purpose  I used ```#define``` macros and its operations, especially "##" (concatenation operation).

![Data Structures](https://media.geeksforgeeks.org/wp-content/uploads/20191010170332/Untitled-Diagram-183.png)

| Data Structures | Based on Structures | Related Structures | Complexity | Check-List |
|-----------------|---------------------|--------------------|------------|------------|
| Stack           | Dynamic Arrays  | <ul><li> Vector</li><li> List</li><li> Some trees</li><ul>|<ul><li> Push: O(1)</li><li> Pop:  O(1)</li><li> Peek: O(1)</li><ul>            |<ul><li>- [x] Done</li><li>- [x] Memeory Leaks</li><li>- [x] Code optimization</li><li>- [x] Explanatory Comments</li><ul>		   |
| Queue           | Double-Linked List      | <ul><li> Queue</li><li> Priority Queue</li><li> Some Trees</li><ul> |<ul><li> Enqueue: O(1)</li><li> Dequeue:  O(1)</li><li> Peek: O(1)</li><ul>            |<ul><li>- [x] Done</li><li>- [x] Memeory Leaks</li><li>- [ ] Code optimization</li><li>- [x] Explanatory Comments</li><ul>		   |
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
			- [Stack Usage-Prerequirements](#stack-usage-prerequirements)
			- [Methods](#methods)
			- [Additional methods](#additional-methods)
			- [Errors and Undefined Behavior](#errors-and-undefined-behavior)
	- [Queue](#queue)
		- [Usage](#usage-1)
			- [Queue Usage-Prerequirements](#queue-usage-prerequirements)
			- [Methods](#methods-1)
			- [Additional methods](#additional-methods-1)
			- [Errors and Undefined Behavior](#errors-and-undefined-behavior-1)
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
- Create main.c in the current directory. Copy the code from the Usage-Prerequirements ([Stack](#stack-usage-prerequirements)/[Queue]()) to your main.c according you compiler.
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
[Stack](https://en.wikipedia.org/wiki/Stack(abstract_data_type)) is a linear data structure in which elements are arranged in **LIFO (last in, first out)** order. It has two basic operations which are changes the stack, **push** and **pop**. Additionally it has **peek** operation. I implemented this structure using dynamic array.

**push** - adds an element to the collection.

**pop** - removes the most recently added element that was not yet removed.

**peek** - gives access to the top without modifying the stack.

![Stack image](https://upload.wikimedia.org/wikipedia/commons/b/b4/Lifo_stack.png)

### Usage
#### Stack Usage-Prerequirements
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

|Method name|Command in the my implementation|Complexity|Returns value|
|-|-|-|-|
|**push** |```stack_push(stack, value)``` |O(1) |Nothing (```void```)|
|**pop** |```stack_pop(stack)``` |O(1)|Value which was peped (```T value```)|
|**peek** |```stack_peek(stack)``` |O(1)|Value which contained at last node (```T value```)|
#### Additional methods
|Method name|Command in the my implementation|Descripton|Returns value|
|-|-|-|-|
|**emtiness** |```stack_empty(stack)```| Checks stack for the emtiness.|```1``` - if queue is empty. ```0``` - if queue is not empty|
|**clear** |```stack_clear(stack)```| Removes all elements from the stack.|Nothing (```void```)|

#### Errors and Undefined Behavior
* First, definition two or more objects. It doesn't work because you trying to redefine the stack-structure. I will think how to fix it but a little bit later.
```C
stack(int) *a = NULL;
stack(int) *b = NULL;
```
## Queue
A [queue](https://en.wikipedia.org/wiki/Queue_(abstract_data_type)) is a collection of entities that are maintained in a sequence and can be modified by the addition of entities at one end of the sequence and removal from the other end of the sequence.
The operation of adding an element to queue is known as **enqueue**, and the operation of removing an element is known as **dequeue**. Other operations may also be allowed, often including a **peek**  or front operation that returns the value of the next element to be dequeued without dequeuing it.
The operations of a queue make it a first-in-first-out (**FIFO**) data structure. In a FIFO data structure, the first element added to the queue will be the first one to be removed.  I implemented this structure using double-linked list.

**enqueue** - the operation of adding an element to the rear of the queue.

**dequeue** - the operation of removing an element from the front of the queue.

**peek** - the operation which returns the value of the last element but without dequeuing.

![Queue image](https://netmatze.files.wordpress.com/2014/08/queue.png)
### Usage
#### Queue Usage-Prerequirements
Before CMake's usage you will need to create the main.c file. There are two a little bit different implementation.

<details>
<summary><b>MSVS-Compiler</b></summary>

```c
#include "./includes/queue.h"
int main() {
  queue(int)* a = NULL;
  queue_constructor(int, a);
  /*
    Paste your code here
  */
  queue_destructor(a);
  return (0);
}
```
</details>
<details>
<summary><b>GNUC-Compiler</b></summary>

```c
#include "./includes/queue.h"
int main() {
  queue(int)* a = queue_constructor(int);
  /*
    Paste your code here
  */
  queue_destructor(a);
  return (0);
}
```
</details>

#### Methods
|Method name|Command in the my implementation|Complexity|Returns value|
|-|-|-|-|
|**enqueue**|```queue_enqueue(queue, value)```|O(1)|Nothing (```void```)|
|**dequeue**|```queue_dequeue(queue)```|O(1)|Value which was dequeued (```T value```)|
|**peek**|```queue_peek(queue)```|O(1)|Value which contained at last node (```T value```)|

#### Additional methods
|Method name|Command in the my implementation|Description|Retunrns value
|-|-|-|-|
|**emtiness**|```queue_empty(queue)```|Checks queue for the emtiness.|```1``` - if queue is empty. ```0``` - if queue is not empty|
|**clear**|```queue_clear(queue)```|Removes all elements from the queue.|Nothing (```void```)|

#### Errors and Undefined Behavior
* First, definition two or more objects. It doesn't work because you trying to redefine the queue-structure. I will think how to fix it but a little bit later.
```C
queue(int) *a = NULL;
queue(int) *b = NULL;
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
- Hash Map Implementation
- Rewrite README
