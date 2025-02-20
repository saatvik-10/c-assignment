#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
using namespace std;

int main()
{
    int a, c[30], d, r = 0, d1;

    // Step 1: Encoder (same as before)
    cout << "Enter the No of Data Bits you want to Enter: ";
    cin >> a;

    while (a + r + 1 > pow(2, r))
    {
        r++;
    }
    cout << "No of data bits to be added " << r << " : Total Bits: " << a + r << endl;

    cout << "Enter the Data Bits One by One:" << endl;
    for (int i = 1; i <= a; ++i)
        cin >> c[i];

    cout << endl << "Data bits entered: ";
    for (int i = 1; i <= a; ++i)
        cout << c[i] << " ";
    cout << endl;

    int data[a + r];
    d = 0;
    d1 = 1;
    for (int i = 1; i <= a + r; ++i)
    {
        if ((i) == pow(2, d))
        {
            data[i] = 0;
            ++d;
        }
        else
        {
            data[i] = c[d1];
            ++d1;
        }
    }

    cout << "Data Bits are Encoded with Parity bits(0): ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    d1 = 0;

    int min, max = 0, parity, s, j;

    // Parity Bit Calculation
    for (int i = 1; i <= a + r; i = pow(2, d1))
    {
        ++d1;
        parity = 0;
        j = i;
        s = i;
        min = 1;
        max = i;
        for (j; j <= a + r;)
        {
            for (s = j; max >= min && s <= a + r; ++min, ++s)
            {
                if (data[s] == 1)
                    parity++;
            }
            j = s + i;
            min = 1;
        }
        if (parity % 2 == 0)
        {
            data[i] = 0;
        }
        else
        {
            data[i] = 1;
        }
    }

    cout << endl << "Hamming codeword bits for even parity are: ";
    for (int i = 1; i <= a + r; ++i)
        cout << data[i] << " ";
    cout << endl << endl;

    // Step 2: Receiver
    int received_data[a + r];
    cout << "Enter the received Hamming codeword (with parity bits): " << endl;
    for (int i = 1; i <= a + r; ++i)
        cin >> received_data[i];

    // Step 3: Syndrome Calculation
    int error_position = 0;
    for (int i = 1; i <= a + r; i = pow(2, d1))
    {
        ++d1;
        parity = 0;
        j = i;
        s = i;
        min = 1;
        max = i;
        for (j; j <= a + r;)
        {
            for (s = j; max >= min && s <= a + r; ++min, ++s)
            {
                if (received_data[s] == 1)
                    parity++;
            }
            j = s + i;
            min = 1;
        }
        if (parity % 2 != 0)
        {
            error_position += i; // Add the position to error_position
        }
    }

    // Step 4: Error Correction or Detection
    if (error_position == 0)
    {
        cout << "No errors detected in the received codeword." << endl;
    }
    else
    {
        cout << "Error detected at position: " << error_position << endl;
        cout << "Correcting the error..." << endl;
        // Flip the bit at the error position
        if (received_data[error_position] == 0)
            received_data[error_position] = 1;
        else
            received_data[error_position] = 0;

        cout << "Corrected Hamming codeword: ";
        for (int i = 1; i <= a + r; ++i)
            cout << received_data[i] << " ";
        cout << endl;
    }

    return 0;
}
