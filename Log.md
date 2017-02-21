# Team No Wei Log #

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
