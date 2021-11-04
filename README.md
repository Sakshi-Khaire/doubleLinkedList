# Implementation of Double LinkedList in C

> This is a type of linkedList contains an extra pointer, typically called ```previous pointer```, together with next pointer and data which are there in singly linked list. 

This program is mainly focus on creating a double linked list with 2 pointer of type struct node i.e. head which will point to the head of the linkedList and tail which will point to the end of the linkedList. If you want to create a multiple double linked list here is the link [doublyLinkedList](http://www.google.com)

![doubleLinkedList](https://media.geeksforgeeks.org/wp-content/uploads/Delete_lincked_list.jpg)

* This first step is to create a structure with field ```data``` and ```a pointer of type structure``` i.e. next and ```a extra pointer of type structure which will point to the previous node```.

```C
    typedef struct node {
        struct node *prev;
        int data;
        struct node *next;
    }NODE;
```

## The following function helps in creating the node with data

```C
    NODE* createNode(int data) {

        //Using malloc for allocating memory of size NODE(i.e. size of the structure).

        //As malloc returns void* we are suppose to typecast it with the appropriate type. That's the reason why it is typecasted with (NODE* ).

        NODE* ptr = (NODE*)malloc(sizeof(NODE));

        //Setting the data to the created node data flied.

        ptr->data = data;

        //Setting Null to the previous feild of the created node.
        ptr->prev = NULL;

        //Setting NULL to the next feild of the created node.

        ptr->next = NULL;

        //Returning the created node

        return ptr;
    }
```

## Following are the function which are performing the basic functionality of single linkedList

*Please also look into the code for the clear understanding(All the important comments are being taken care of)*

```C
    addAtFirst(int data) //Adding the node at the beginning of the linked list

    addAtEnd(int data) //Adding the node at the end of the linked list

    deleteFirst() //Removes the first node from the linked list pointed by root

    deleteLast() //Removes the last node from the linked list pointed by root

```

# How to run the code

* Download the source code
* Open the terminal (in mac) for cmd (in windows) and navigate to the folder in with the source code is present
* Type the command ```gcc linkedList.c``` . This command will compile the code.
* To run the code type the command ```./a.out``` in the same terminal. This command will give you the output.