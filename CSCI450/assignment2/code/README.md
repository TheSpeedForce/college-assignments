CSCI 450 Assignment 2 Report
============================

## Overview

This is prototype for online store using MVC pattern. To use RMI, a controller object is made using the store model and view. The server binds the controller object and the client uses it. 

## Execution

**Tesla**: Use makefile to make. Command: `make all`. For server: `run-server`. For client: `run-client`.

**rrpc machines**: As classes compiled in tesla do not run in rrpc machine, all commands need to be run on both rrpc machines (rrpc01 (*for server*), rrpc02 (*for client*)).

##### rrpc01 command (server)
`bash autorunServer.sh`

##### rrpc02 command (client)
`bash autorunClient.sh`

## Files Overview

### Item.java
**Purpose**: Create item object for showing

**Properties**: name, type, description, cost, count

**Methods**: Getters, Setters, printItem


### User.java
**Purpose**: Create user object for using the program

**Properties**: username, password, name

**Methods**: Getters, Setters


### Customer.java
**Purpose**: Create customer object for customer. inherits User

**Properties**: User properties, cart

**Methods**: None


### Admin.java
**Purpose**: Create admin object for showing, Inherits user

**Properties**: User properties

**Methods**: None


### Store_Model.java
**Purpose**: Create store model object to change data

**Properties**: items (list of Item), users (list of Users)

**Methods**: getItems, login, addItem, purchaseCart, updateItem, removeItem, addCustomer, removeCustomer, addAdmin, removeAdmin


### Store_View.java
**Purpose**: Create store view object for showing user store functions

**Properties**: userType, admin, customer

**Methods**: showMessage, login,  loginCheck, browseItems, customerMenu, adminMenu



### Store_Controller.java
**Purpose**: interface for creating store. Extends Remote for rmi

**Properties**: theModel, theView

**Methods**: getTheModel, getTheView

### Store_Controller.java
**Purpose**: Create store controller object for to control model and view. Implements store

**Properties**: theModel, theView

**Methods**: getTheModel, getTheView

### Remote_Store_Controller.java
**Purpose**: Create store controller object and bind to URL.

**Actions**: Create items, customer and admins for test data.

### Client_Store_Controller.java
**Purpose**: Get store controller object and run program.

**Actions**: Run login, loginCheck and browseItems for test





