# Managing-Materials
 Read Files and Strings


# Description of the problem
In this exercise, a program is created that manages material information so that the needs for the supply of raw materials are calculated and the production of intermediate and
products is programmed in order to meet some orders. The distinction of materials into categories follows the following rules:

1) Raw materials: Purchased from external suppliers. <br />
2) Intermediate products: Produced from other intermediates and/or raw materials. They are used in the production of other products (intermediate or final). <br />
3) Final products: Intended for sale and not for the production of others.<br />

Each product (intermediate or final) has a certain composition corresponding to the types of raw materials and/or
intermediate products required for its manufacture. The composition also includes the
quantity of each component necessary for the manufacture of a product unit.

The user is given the opportunity to see on the screen the available materials as well as the components of a material of the of his choice.

# Input File
The input file has two parts. The first part describes the types of materials and the second part describes the
pending orders. Each part starts with a line that contains a non-negative integer that corresponds to the
in the number of lines that follow. The file
must have information on pending final product orders.

Example form:
'number of kinds of materials' <br />
'code' 'name' 'stock quantity' 'number of ingredients' 'code 1' 'quantity 1' ... <br />

'Order count' <br />


An example input file
8 <br />
1 Glass 3 0 <br />
2 Tire 5 0 <br />
3 Rim 3 0 <br />
4 Piston 3 0 <br />
5 Belt 2 0 <br />
6 Wheel 10 2 2 1 3 1 <br />
7 Engine 2 2 4 4 5 2 <br />
8 Car 5 3 6 4 7 1 1 6 <br />
1 <br />
8 10 <br />

The user can obtain an output file information about all kinds of
(number of units available and number of units required to cover orders).


# How to run
Run .c file with the appropriate input file. 

The project has been created in Devc++