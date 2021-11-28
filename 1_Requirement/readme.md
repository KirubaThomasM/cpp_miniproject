# Requirements
## Introduction
Library inventory and record management system is implemented as a mini-project.

### Benefits
Can easily store and Retrive record of library records
 
## Cost and Features
Feature | Cost | Time
| ----- | ----- | ----- |
| E-Library|   Low | 10h    |

## Defining Our System


## SWOT ANALYSIS
![SWOT Analysis](https://github.com/KirubaThomasM/cpp_miniproject/blob/main/1_Requirement/SWOT.png)

# 4W&#39;s and 1&#39;H

## Who
Library Managers and Customers

## What
E-Library platform with less human contact which is very useful during this covid times.

## When
This can be implemented when there is a need for maintainence of huge records of several articles and book collection.

## Where
Any library requirements.

## How
This can be implemented first by searching the book/article with the database.
If matching found, it will provide us the provision to update the details or book an order.
To update the details, one must have admin access.

## Detail requirements
### High Level Requirements 

| ID | Description | Category | Status | 
| ----- | ----- | ------- | ---------|
| HR01 | Store the record of books/articles list | Techincal | Implemented | 
| HR02 | Able to add or remove when you're an admin| Techincal | Implemented |
| HR03 | Have access to buy as a customer | Techincal | Implemented |
| HR04 | Data should not be lost in case of faliure | Scenario | FUTURE |

### Low level Requirements
 
| ID | Description | HLR ID | Status (Implemented/Future) |
| ------ | --------- | ------ | ----- |
| LR01 | Create and maintain a list with varities of books/articles and their necessary attributes | HR01 | Implemented |
| LR02 | The list should expand and compress as new stuffs added or removed| HR02 | Implemented |
| LR03 | Authenication for admin access | HR02 | Implemented |
| LR04 | If customer searches for an out of stock or unknown book, "No Record Found" message should be displayed | HR03 | Implemented |
| LR05 | If matches found for the searched book and bought some copies, copies in stock must be dedeucted as applicable | HR03 | Implemented |
