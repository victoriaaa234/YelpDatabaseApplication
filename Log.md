# Team No Wei Log #

## Febraury 24th, 2017
### General
Team No Wei completed the implementation of Table and Record. Currently, we are working on implementing the functions of Database. We have successfully incorporated the test cases that were given to us by Team 19. However, the test cases we were given were filled with issues and we were required to fix them. Furthermore, Kevin is continuing to work on the Query Parser for the Database API.

### Progress:
- Kevin - Implemented Select and From on the Query.
- Victoria - Completed Table API, Database other API endpoints, and Cross Join/Natural Join.
- Yerania - Completed Table API and Record API endpoints. 

### TODO:
- Parse the Where clause
- Implement a Decision Tree for each record.


## February 20th, 2017
### General
Team No Wei has successfully completed all the test cases. Kevin has completed the test cases and uplaoded the submission to eCampus. Victoria corrected Kevin's submission by renaming and resubmitting the test cases and emailed the test cases to the Group 17 so that they can begin testing their implementation of the code. Furthermore, Victoria is continuing to work on the Database API and has brought attention the potential issues of utilizing Boost with Query.

### Progress:
- Kevin - Finished test cases and submitted to eCampus. Checkpoint 2 Completed.
- Victoria - Continuing to implement the Database API.
- Yerania - Continuing to implement Table API.

### TODO:
- Finish Database API
- Receive test cases from Group 19.
- Incorporate test cases into our Visual Studio 2015 Solution.
- Bring group up to speed on each others implementations of the API.

## February 15th, 2017
### General
Team No Wei split our efforts into different tasks during the meeting at the HRBB Louge. Yerania and Victoria worked on implementing the database for Checkpoint 3. Kevin worked on implementing the test cases. Furthermore, we worked more on the details of our implementation as a team. 

### Progress:
- Kevin - Worked on linking the DLL and the Header file to a database test file. Utilizing the Catch C++ library.
- Victoria - Started working on the Database API implementation.
- Yerania - Completed Record implementation and began implementation work on Table API.

### TODO:
- Finish Test Cases
- Finish Implementation of Database API
- Analyze code written for test cases and Database API.

## February 11th, 2017
### General
Team No Wei completed the API documentation (See commit #c232772e4d76581e5cc0a905ae644e666c7b0428). We noticed a bug in our implementation of the record API. Following the standards defined previously, we created a Github Issue and fixed it accordingly. Overall, Team No Wei has completed Checkpoint 1 and is waiting to submit on eCampus. After submission, we will close Milestone 1. 

### Progress:
- Kevin - Explained the structure of API, documentation, and code to Victoria and worked on documentation.
- Victoria - Finished setting up developer environment and understanding code base.
- Yerania - Completed API documentation.

### TODO:
- Update the Milestones to contain all issues.
- Submit ZIP file for Checkpoint 1.
- Receive code for Checkpoint 2.
- Review further implementation details required.
- Plan meeting times and scrum times.

## Febraury 9th, 2017
### General 
This was our first meeting of Team No Wei to work on this project. 
We analyzed the requirements of the first checkpoints and decided that Github Issues with Labels and Milestones would be the best implementation of synchronization between us. 
We first created all of the milestones corresponding to the dates that are in the rubric. 
In order to keep Team No Wei on track, we implemented a system of issues and assignees to implement the functionality.
All information about the required implementation and code is linked to every issue. 
Each commit will be tagged with the issue that attempts to resolve the issue. For more information look at our issues and each commit that solves the issue will be tagged with the commit ID. 

### Database API
We completed the entirety of the Database API that we will be giving to another team. 
More information about the internal functionality is documented in the Visual Studio 2015 C++ code.  
We implemented the database API in the following format:

##### Database Library
- Classes
  - Database
    - Query
  - Table
  - Record
  
### Standards
Furthermore, we came to an agreement on coding practices and standards.
- We implemented a system of buddying code prior to any commit. 
- The requirement before pushing code is that another member of the team must approve and fully understand the changes.
- We will be implementing camel case and other coding practices that we learned in class. 
- Most likely, we will be implementing some form of Git Flow in our project.
- In order to work on an issue, the issue must be assigned to you and all commits must be regarding that issue. 
- In order to close the issue, another member of the team must review all changes and ensure that they pass the requirements. 
