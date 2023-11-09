/*Write a C program to find addition of two polynomials*/

#include <stdio.h>
#include <stdlib.h>

// Structure for a term in a polynomial
struct Term {
    int coefficient;
    int exponent;
    struct Term* next;
};

typedef struct Term Polynomial;

// Function to insert a term into a polynomial
void insertTerm(Polynomial** poly, int coeff, int exp) {
    Polynomial* newNode = (Polynomial*)malloc(sizeof(Polynomial));
    newNode->coefficient = coeff;
    newNode->exponent = exp;
    newNode->next = *poly;
    *poly = newNode;
}

// Function to display a polynomial
void displayPolynomial(Polynomial* poly) {
    Polynomial* current = poly;
    while (current != NULL) {
        printf("%dx^%d", current->coefficient, current->exponent);
        current = current->next;
        if (current != NULL) {
            printf(" + ");
        }
    }
    printf("\n");
}

// Function to add two polynomials
Polynomial* addPolynomials(Polynomial* poly1, Polynomial* poly2) {
    Polynomial* result = NULL;
    while (poly1 != NULL && poly2 != NULL) {
        if (poly1->exponent > poly2->exponent) {
            insertTerm(&result, poly1->coefficient, poly1->exponent);
            poly1 = poly1->next;
        } else if (poly1->exponent < poly2->exponent) {
            insertTerm(&result, poly2->coefficient, poly2->exponent);
            poly2 = poly2->next;
        } else {
            int sum_coeff = poly1->coefficient + poly2->coefficient;
            if (sum_coeff != 0) {
                insertTerm(&result, sum_coeff, poly1->exponent);
            }
            poly1 = poly1->next;
            poly2 = poly2->next;
        }
    }

    while (poly1 != NULL) {
        insertTerm(&result, poly1->coefficient, poly1->exponent);
        poly1 = poly1->next;
    }

    while (poly2 != NULL) {
        insertTerm(&result, poly2->coefficient, poly2->exponent);
        poly2 = poly2->next;
    }

    return result;
}

int main() {
    Polynomial* poly1 = NULL;
    Polynomial* poly2 = NULL;

    // Insert terms into the first polynomial (5x^3 + 3x^2 + 2x^1)
    insertTerm(&poly1, 5, 3);
    insertTerm(&poly1, 3, 2);
    insertTerm(&poly1, 2, 1);

    // Insert terms into the second polynomial (4x^2 + 6x^1 + 8x^0)
    insertTerm(&poly2, 4, 2);
    insertTerm(&poly2, 6, 1);
    insertTerm(&poly2, 8, 0);

    printf("Polynomial 1: ");
    displayPolynomial(poly1);
    printf("Polynomial 2: ");
    displayPolynomial(poly2);

    Polynomial* result = addPolynomials(poly1, poly2);

    printf("Addition of Polynomials: ");
    displayPolynomial(result);

    return 0;
}

/*Output
Polynomial 1: 2x^1 + 3x^2 + 5x^3
Polynomial 2: 8x^0 + 6x^1 + 4x^2
Addition of Polynomials: 4x^2 + 6x^1 + 8x^0 + 5x^3 + 3x^2 + 2x^1
*/