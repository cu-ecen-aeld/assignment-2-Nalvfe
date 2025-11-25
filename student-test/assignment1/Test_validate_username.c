#include "unity.h"
#include <stdbool.h>
#include <stdlib.h>
#include "../../examples/autotest-validate/autotest-validate.h"
#include "../../assignment-autotest/test/assignment1/username-from-conf-file.h"

/**
* This function should:
*   1) Call the my_username() function in autotest-validate.c to get your hard coded username.
*   2) Obtain the value returned from function malloc_username_from_conf_file() in username-from-conf-file.h within
*       the assignment autotest submodule at assignment-autotest/test/assignment1/
*   3) Use unity assertion TEST_ASSERT_EQUAL_STRING_MESSAGE to verify the two strings are equal.  See
*       the [unity assertion reference](https://github.com/ThrowTheSwitch/Unity/blob/master/docs/UnityAssertionsReference.md)
*/
void test_validate_my_username()
{
    /**
     * TODO: Replace the line below with your code here as described above to verify your /conf/username.txt 
     * config file and my_username() functions are setup properly
     */
    // 1) autotest-validate.c の my_username() からハードコードしたユーザー名を取得 
    const char *hardcoded_username = my_username();

    // 2) conf/username.txt から読み込んだユーザー名を取得（mallocされた文字列）
    char *conf_username = malloc_username_from_conf_file();

    // 読み込みに失敗していないかチェック
    TEST_ASSERT_NOT_NULL_MESSAGE(conf_username,
                                "Failed to read username from conf/username.txt");

    TEST_ASSERT_EQUAL_STRING_MESSAGE(
        hardcoded_username, 
        conf_username,
        "Username from my_username() does not match conf/username.txt"
    );

    // 4) 動的確保された文字列を解放
    free(conf_username);
}



