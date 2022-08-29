/* Programming assignment 1

This program simulates a mathematics quiz game. It is a menu-driven program. In this quiz the user can answer 1 to 5 questions. Users can sellect how many questions do thwy want to answer. These questions are simple mathematical questions. When you input correct question you can skip next question, if your answer is incorrect then you will return to the main menu. At the end of the quiz users can see their's results.


Author: Ceren Ucan
Date: 20 November 2021
*/

#define SIZE 50
#define ArrSIZE 5

#include <stdio.h>
int main(void)
{
    int i;     // variable for menu options
    int j = 0;          //user's input for sellected questions question number 
    int ans1;           //stores users answers correct answer
    int countCorrect;   //stores the correct answers
    int countInCorrect; //stores the incorrect answers
    int flagOption3;    //flags the option3 if the users selects it before
    int total=0;        // score

    int answers[5] = {23, 1, 11, 0, 20}; //questions' answers

    char question_list[SIZE][SIZE] = { //5 Questions in Quiz
        "Question 1) 8 + 3 * 5 = ?",
        "Question 2) 4 / 2 - 1 = ?",
        "Question 3) 7 + 1 * 4 =?",
        "Question 4) 6 / 3 - 2 = ?",
        "Question 5) 5 * 5 - 5 = ?"};

    do //beginning of do loop
    {
        printf("\nWelcome to the Mathematic Quiz\n\n");

        printf("1) Enter the number of questions to be asked for this round of the quiz\n\n"); //print the first option

        printf("2)Start and play quiz\n\n"); //print the second option

        printf("3)Display the number of questions that were answered (i) correctly and (ii) incorrectly for this round.\n\n"); //print the third option

        printf("4)Exit Program\n\n"); //print the fourth option

        scanf("%d", &i); // get user input for select options 

        if (i == 1) //when the user enters 1
        {

            flagOption3 = 0; //reset to zero

            printf("Enter how many question you want (Max: 5): \n\n");

            scanf("%d", &j); //get user input for how many questions they need

            while (j > 5 || j < 0)
            {
                printf("Please enter a question number in between 0-5\n\n");
                scanf("%d", &j); //get user input for how many questions they need
            } //end while

            flagOption3 = 0;

            printf("You have successfully selected number of questions you want for this round. Please select second option to start the game. \n\n");
        } //end if

        else if (i == 2)
        {
            //reset the count at the start of this round so that it will not record every round
            int z; //user's answer 
            printf("%d", j);
            flagOption3 = 1;
            if (j == 0)
            {
                printf("Please first enter the number of question you want by using the first option, now you will be returned to the menu.\n\n");
            } //end if
            else
            {

                countInCorrect = 0; //for incorrect answers
                countCorrect = 0; //for correct answers

                for (z = 0; z < j; z++)
                {

                    printf(" The questions is: %s \n\n", question_list[z]);
                    printf("Enter your answer: ");
                    scanf("%d", &ans1);
                    if (answers[z] == ans1)
                    {
                        printf("Correct answer\n\n");
                        printf("You have scored 5 point\n\n");
                        printf("You will move on to the new question\n\n");
                        total = total+5;
                        countCorrect += 1;
                    } //end if
  
                    else
                    {
                        printf("Incorrect answer\n\n");
                        printf("You have scored 0 points, correct answer is %d, you will return to the menu\n\n",answers[z]);
                    
                        z = j; //breaks the loop
                        countInCorrect += 1;
                    } //end else
                } //end for

                if (z == j)
                {
                    printf("You answered all questions successfully, you will be returned to the menu for further action\n\n");
                } //end if
            } // end else 
        } //end else if

        else if (i == 3)
        {

            if (flagOption3 != 0)
            {
                printf(" In this round, you have %d correct answers and %d wrong answers \n\n", countCorrect, countInCorrect); //user can see their result
            } // end if
            else
            {
                printf("Please first select the second option\n\n"); //user should enter 2 to start the quiz
            } //end else
        } //end else if

    } while (i != 4); //end do

    printf("Your total score is: %d \n\n", total); //scor appears
    return 0; 
} //end the program
