#include <stdio.h>

int main() {
    int students, i;
    float marks[100], average;
    int belowAverage = 0;
    float sum = 0;

    printf("=========================================\n");
    printf("   AI Educational Equity Analyzer\n");
    printf("=========================================\n");

    printf("Enter number of students: ");
    scanf("%d", &students);

    // Input marks
    for(i = 0; i < students; i++) {
        printf("Enter marks of student %d: ", i + 1);
        scanf("%f", &marks[i]);
        sum += marks[i];
    }

    // Calculate average
    average = sum / students;

    printf("\n=========================================\n");
    printf("Average Marks = %.2f\n", average);
    printf("=========================================\n");

    // Analyze students
    printf("\nStudent Performance Analysis:\n");

    for(i = 0; i < students; i++) {

        printf("\nStudent %d --> Marks = %.2f\n", i + 1, marks[i]);

        if(marks[i] < average) {
            printf("Status : Needs Support\n");
            printf("AI Suggestion : Extra mentoring recommended.\n");
            belowAverage++;
        }
        else {
            printf("Status : Performing Well\n");
            printf("AI Suggestion : Encourage advanced learning.\n");
        }
    }

    // Equity analysis
    printf("\n=========================================\n");
    printf("      Educational Equity Report\n");
    printf("=========================================\n");

    printf("Total Students           : %d\n", students);
    printf("Students Needing Support : %d\n", belowAverage);
    printf("Students Performing Well : %d\n", students - belowAverage);

    if(belowAverage > students / 2) {
        printf("\nAI Insight:\n");
        printf("High learning inequality detected.\n");
        printf("Institution should improve support systems.\n");
    }
    else {
        printf("\nAI Insight:\n");
        printf("Learning environment appears balanced.\n");
    }

    printf("\n=========================================\n");
    printf("   Analysis Completed Successfully\n");
    printf("=========================================\n");

    return 0;
}