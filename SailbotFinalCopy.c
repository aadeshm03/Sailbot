#pragma once

/* Author: Aadesh Mehra
 * Student Number: 39288733
 * Date:             09/09/2020 7:08:16 PM
 * Email: aadeshm03@gmail.com
 */

#define _CRT_SECURE_NO_WARNINGS
#define TRUE 1
#define FALSE 0

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/**
 * Bounds the provided angle between [-180, 180) degrees.
 * Ex. 360 becomes 0, 270 becomes -90, -450 becomes -90.
 * @param angle Input angle in degrees.
 * @return The bounded angle in degrees.
 */
float boundTo180(float angle)
{
    float inpangle = angle;
    float bounded = 0;

    //checks if the angle is greater or less than the bounds
    if (inpangle >= 180)
    {
        bounded = inpangle;
        //continues loop until the desired angle is within the bounds
        while (bounded >= 180)
        {
            bounded = bounded - 360;
        }
    }

    else if (inpangle < -180)
    {
        bounded = inpangle;
        while (bounded < -180)
        {
            bounded = bounded + 360;
        }
    }

    else
    {
        bounded = inpangle;
    }
    return bounded;
}

/*
 * Determines whether |middle_angle| is in the acute angle between the other two bounding angles.
 * Note: Input angles are bounded to 180 for safety.
 * Ex. -180 is between -90 and 110 but not between -90 and 80.
 * @param first_angle First angle in degrees.
 * @param middle_angle Middle angle in degrees.
 * @param second_angle Second angle in degrees.
 * @return Whether |middle_angle| is between |first_angle| and |second_angle| (exclusive).
 */

bool isAngleBetween(float first_angle, float middle_angle, float second_angle)
{
    float firstangle = boundTo180(first_angle);
    float secondangle = boundTo180(second_angle);
    float middleangle = boundTo180(middle_angle);
    float acute = 0;
    bool A = 0;
    float B;

    //converts all angles to positive value
    if (firstangle < 0)
        firstangle = firstangle + 360;

    if (secondangle < 0)
        secondangle = secondangle + 360;

    if (middleangle < 0)
        middleangle = middleangle + 360;

    // Ensures the larger angle is always the first
    if (secondangle > firstangle)
    {
        B = firstangle;
        firstangle = secondangle;
        secondangle = B;
    }

    if ((firstangle > middleangle) && (secondangle < middleangle) && (firstangle - secondangle < 180))
        A = TRUE;

    //checks for the case when the first and second angle are in the fourth and first quadrant 
    else if ((secondangle < middleangle) && (firstangle < middleangle) && (firstangle - secondangle > 180))
        A = TRUE;

    else if ((secondangle > middleangle) && (firstangle > middleangle) && (firstangle - secondangle > 180))
        A = TRUE;

    else
        A = FALSE;

    return A;
}


