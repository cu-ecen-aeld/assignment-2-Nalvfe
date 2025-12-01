CC      = $(CROSS_COMPILE)gcc
CFLAGS  = -Wall -Werror -g
TARGET  = writer
OBJS    = writer.o

# デフォルトターゲット：writer をビルド
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# オブジェクトファイル
writer.o: writer.c
	$(CC) $(CFLAGS) -c $<

# おまけで all ターゲットも writer をビルドするように
all: $(TARGET)

# クリーン：バイナリと .o を削除
clean:
	rm -f $(TARGET) *.o

.PHONY: all clean
