#include <stdio.h>
#include <stdlib.h>
#include <syslog.h>

int main(int argc, char *argv[])
{
    // syslog を LOG_USER facility で使用開始
    openlog("writer", LOG_PID, LOG_USER);

    // 引数チェック： ./writer <writefile> <writestr>
    if (argc != 3) {
        syslog(LOG_ERR, "Invalid number of arguments: %d", argc - 1);
        fprintf(stderr, "Usage: %s <writefile> <writestr>\n", argv[0]);
        closelog();
        return 1;
    }

    const char *writefile = argv[1];
    const char *writestr  = argv[2];

    // ファイルを「書き込みモード」で開く（ディレクトリは呼び出し側が作っている前提）
    FILE *fp = fopen(writefile, "w");
    if (fp == NULL) {
        syslog(LOG_ERR, "Error opening file: %s", writefile);
        perror("fopen");
        closelog();
        return 1;
    }

    // 要求仕様のメッセージ：
    // 「Writing <string> to <file>」 を LOG_DEBUG レベルでログ出力
    syslog(LOG_DEBUG, "Writing %s to %s", writestr, writefile);

    // ファイルへ書き込み
    if (fprintf(fp, "%s", writestr) < 0) {
        syslog(LOG_ERR, "Error writing to file: %s", writefile);
        perror("fprintf");
        fclose(fp);
        closelog();
        return 1;
    }

    // ファイルを閉じる
    if (fclose(fp) != 0) {
        syslog(LOG_ERR, "Error closing file: %s", writefile);
        perror("fclose");
        closelog();
        return 1;
    }

    // syslog 終了
    closelog();
    return 0;
}

