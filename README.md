# Material information management
> A simple material information management program.
## Table of contents
* [General Info](#general-information)
* [Technologies Used](#technologies-used)
* [Screenshots](#screenshots)
* [Room for Improvement](#room-for-improvement)
* [Setup](#setup)
* [Acknowledgements](#acknowledgements)

## General Information
Α program that will manage material information. Costs for the supply of raw materials will be calculated and the production of intermediates and
final products in order to satisfy some orders.
The distinction of materials into categories
follows the following rules:

- Raw materials
- Intermediate products[^1]
- Final products

```mermaid
graph TD;
    A-->B;
    A-->C;
    A-->D;
    C-->E;
    C-->F;
    D-->G;
    D-->H;
```





## Screenshots

## Room for Improvement

## Technologies Used
C Integrated Development Environment (IDE)

## Setup
Basic project for language learning. <br />
External text input with two parts
- The first part describes the types of materials 
- The second part the pending orders. 

````
```
<Πλήθος ειδών υλικών>
<Κωδικός> <Όνομα> <Ποσότητα αποθήκης> <Πλήθος συστατικών> <Κωδικός1> <ποσότητα1>...
```
````

<Πλήθος παραγγελιών>
  ```
## Acknowledgements
- This project was one of my very first project when i was learning C.
- This project was created for the requirements of the lesson Introduction to Computers.

[^1]: Intermediate products can be an intermediate composition..
