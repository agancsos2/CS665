# README                                    

## ABOUT                               
* NAME       : AMGDeliveryDispatch
* Author     : Abel Gancsos
* Version    : v. 1.0.0

## Implementation Details  
This utility, AMGDeliveryDispatch, is a system that helps assign delivery orders to appropriate vans based on certain criteria once the purchase has been completed.  The system starts by taking in a certain number of orders containing various number of items from different customers at different shops.  The assignment process then scans the type of items in the orders, checks if it's the customers birthday, calculates the total distance of the delivery, and then checks if there's an available driver.  To ensure appropriate delivery time and proper state of the product upon delivery, the assignment process also checks for any traffic that could occur while in transit.  If an order is not able to be dispatched due to lack of drivers or unavailable resources, the order waits until a proper resource has become available.  Once the driver has been assigned, the customer is then notified of a scheduled delivery.

### Product types
* Food
   * Cold
   * Warm
* Flower Bouquets
* Gift chocolate boxes

### Requirements
* If a cold meal is to be delivered  more than 2 miles away, it must go to a van with a freezer.
* If it's a customers birthday and they have an order, they must receive a gift chocolate box
* When there is a lot of traffic, ALL cold foods must go to vans with freezers. 

### Assumptions
* The order has already been completed and paid for by the time the process enters into this utility.
* In addition to notifiying the customer of an expected delivery, the driver is told where to pick the order up.
* Although the system would use GPA coordinates to calculate driver location, the distance is calculated by random numbers in miles for simulation purposes.
* More product types can be added in the future.
* Food types can be of any type.
* Flower bouquets can include any flower combination.
* Chocolate boxes may contain different chocolate types.
* Drivers and products are predefined and the user doesn't control this data.
* One tick in the simulation is the same as travelling one mile in distance.
* An order can have multiple items, but no more than one item of the same type.
* The total distance of a delivery is considered the distance of the driver from the store plus the distance of the customer from the store.
* An order doesn't become a delivery until it is ready for dispatch.

## Simulation criteria
* 10 drivers
* 5 shops with 5 product types
* 20 customer orders
* 1 case of lots of traffic
       
## Implementation Description


## FLAGS                                    

## PREREQUISITES
### G++ compiler
#### Windows
Should come with Visual Studio 2017 in the form of devenv, but you can also try using Bloodshed Dev C++
#### Mac
Should come with XCode command-line tools
#### Linux
Should be installable using internal package installer
### CMake
#### Windows
Should come with Visual Studio 2017 
#### Mac
Can be installed from https://cmake.org/download/
#### Linux
Can be installed from https://cmake.org/download/

## Build
This can be built either using one of the run scripts or manually using the following instructions
### Windows
* Import into a new C++ project
* Build using Visual Stuido 2017

### Mac
Either import it into a new XCode project or compile on the command-line using g++ -std=c++11

### Linux
Compile using g++ -std=c++11

## Execute
Run the target that was generated in the build step
