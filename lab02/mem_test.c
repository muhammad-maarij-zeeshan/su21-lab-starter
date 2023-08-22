#include <stdio.h>

#define NO_WORDS 2
#define SIZE_WORDS NO_WORDS << 3

typedef struct
{
    unsigned long long double_word[NO_WORDS];
} arr_t __attribute__((aligned(SIZE_WORDS)));

arr_t store_byte_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_byte_expected_data[8] =
    { // double_word0         double_word1
        {0x00000000000000EF, 0x0000000000000000},
        {0x000000000000BE00, 0x0000000000000000},
        {0x0000000000AD0000, 0x0000000000000000},
        {0x00000000DE000000, 0x0000000000000000},
        {0x000000EF00000000, 0x0000000000000000},
        {0x0000BE0000000000, 0x0000000000000000},
        {0x00AD000000000000, 0x0000000000000000},
        {0xDE00000000000000, 0x0000000000000000}};

arr_t store_half_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_half_word_expected_data[8] =
    {
        {0x000000000000BEEF, 0x0000000000000000},
        {0x0000000000ADBE00, 0x0000000000000000},
        {0x00000000DEAD0000, 0x0000000000000000},
        {0x000000EFDE000000, 0x0000000000000000},
        {0x0000BEEF00000000, 0x0000000000000000},
        {0x00ADBE0000000000, 0x0000000000000000},
        {0xDEAD000000000000, 0x0000000000000000},
        {0xDE00000000000000, 0x00000000000000EF}};

arr_t store_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_word_expected_data[8] =
    {
        {0x00000000DEADBEEF, 0x0000000000000000},
        {0x000000DEADBEEF00, 0x0000000000000000},
        {0x0000DEADBEEF0000, 0x0000000000000000},
        {0x00DEADBEEF000000, 0x0000000000000000},
        {0xF00DC0DE00000000, 0x0000000000000000},
        {0x0DC0DE0000000000, 0x00000000000000F0},
        {0xC0DE000000000000, 0x000000000000F00D},
        {0xDE00000000000000, 0x0000000000F00DC0}};

arr_t store_double_word_data[8] =
    {
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000},
        {0x0000000000000000, 0x0000000000000000}};

arr_t store_double_word_expected_data[8] =
    {
        {0xDEADBEEFF00DC0DE, 0x0000000000000000},
        {0xADBEEFF00DC0DE00, 0x00000000000000DE},
        {0xBEEFF00DC0DE0000, 0x000000000000DEAD},
        {0xEFF00DC0DE000000, 0x0000000000DEADBE},
        {0xF00DC0DE00000000, 0x00000000DEADBEEF},
        {0x0DC0DE0000000000, 0x000000DEADBEEFF0},
        {0xC0DE000000000000, 0x0000DEADBEEFF00D},
        {0xDE00000000000000, 0x00DEADBEEFF00DC0}};

int compare_arrays(arr_t *actual, arr_t *expected)
{
    for (int i = 0; i < 8; ++i)
    {
        for (int j = 0; j < NO_WORDS; ++j)
        {
            if (actual[i].double_word[j] != expected[i].double_word[j])
            {
                printf("Mismatch at line %d and double_word %d\n", i, j);
                return 0;
            }
        }
    }
    return 1;
}

int store_byte_test()
{
    // EF, BE, AD, DE, EF, BE, AD, DE
    arr_t data_1 = {{0xDEADBEEFDEADBEEF, 0x00000000000000FF}};
    arr_t data_2 = {{0x0000000000000000, 0x00000000000000FF}};

    for (int i = 0; i < 8; ++i)
    {
        store_byte_data[i].double_word[0] = data_1.double_word[0] & data_1.double_word[1];
        store_byte_data[i].double_word[1] = data_2.double_word[0] & data_2.double_word[1];
        data_1.double_word[1] = data_1.double_word[1] << 8;
        data_2.double_word[1] = data_2.double_word[1] << 8;
    }

    return compare_arrays(store_byte_data, store_byte_expected_data);
} // store_byte_test

int store_half_word_test()
{

    // BEEF, ADBE, DEAD, EFDE, BEEF, ADBE, DEAD, EFDE
    arr_t data_1 = {{0xDEADBEEFDEADBEEF, 0x000000000000FFFF}};
    arr_t data_2 = {{0x00000000000000EF, 0xFF00000000000000}};

    for (int i = 0; i < 8; ++i)
    {
        store_half_word_data[i].double_word[0] = data_1.double_word[0] & data_1.double_word[1];
        store_half_word_data[i].double_word[1] = data_2.double_word[0] & data_2.double_word[1];
        data_1.double_word[1] = data_1.double_word[1] << 8;
        data_2.double_word[1] = data_2.double_word[1] >> 8;
    }

    return compare_arrays(store_half_word_data, store_half_word_expected_data);
} // store_half_word_test

int store_word_test()
{
    // DEADBEEF, F00DC0DE
    arr_t data_1 = {{0x00000000DEADBEEF, 0x00000000FFFFFFFF}};
    arr_t data_2 = {{0x0000000000000000, 0xFFFFFFFFFFFFFFFF}};

    for (int i = 0; i < 8; ++i)
    {
        store_word_data[i].double_word[0] = data_1.double_word[0] & data_1.double_word[1];
        store_word_data[i].double_word[1] = data_2.double_word[0] & data_2.double_word[1];
        data_2.double_word[0] = ((data_2.double_word[0] << 8) + ((data_1.double_word[0] & (0xFF00000000000000)) >> 56));
        data_1.double_word[0] = data_1.double_word[0] << 8;
        data_1.double_word[1] = data_1.double_word[1] << 8;
        if (i == 3)
        {
            data_1.double_word[0] = 0xF00DC0DE00000000;
        }
    }

    return compare_arrays(store_word_data, store_word_expected_data);
} // store_word_test

int store_double_word_test()
{
    // DEADBEEFF00DC0DE
    arr_t data_1 = {{0xDEADBEEFF00DC0DE, 0xFFFFFFFFFFFFFFFF}};
    arr_t data_2 = {{0x0000000000000000, 0xFFFFFFFFFFFFFFFF}};

    for (int i = 0; i < 8; ++i)
    {
        store_double_word_data[i].double_word[0] = data_1.double_word[0] & data_1.double_word[1];
        store_double_word_data[i].double_word[1] = data_2.double_word[0] & data_2.double_word[1];
        data_2.double_word[0] = ((data_2.double_word[0] << 8) + ((data_1.double_word[0] & (0xFF00000000000000)) >> 56));
        data_1.double_word[0] = data_1.double_word[0] << 8;
        data_1.double_word[1] = data_1.double_word[1] << 8;
    }

    return compare_arrays(store_double_word_data, store_double_word_expected_data);
} // store_double_word_test

int main()
{
    if (store_byte_test())
        printf("store_byte_test -> Pass \n");
    else
        printf("store_byte_test -> Fail \n");

    if (store_half_word_test())
        printf("store_half_word_test -> Pass \n");
    else
        printf("store_half_word_test -> Fail \n");

    if (store_word_test())
        printf("store_word_test -> Pass \n");
    else
        printf("store_word_test -> Fail \n");

    if (store_double_word_test())
        printf("store_double_word_test -> Pass \n");
    else
        printf("store_double_word_test -> Fail \n");

    return 0;
}