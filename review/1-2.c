#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <pthread.h>

#define NUM_THREADS 2 // 线程数

// 全局变量
pthread_t threads[NUM_THREADS];
pthread_mutex_t mutex;
int stopStoring = 0; // 停止存储标志

// 生成文件名
char* generateFilename() {
    time_t rawTime;
    struct tm* localTime;
    struct timespec currentTime;

    clock_gettime(CLOCK_REALTIME, &currentTime);
    rawTime = currentTime.tv_sec;
    localTime = localtime(&rawTime);

    int milliseconds = currentTime.tv_nsec / 1000000;  // 毫秒级别的时间戳

    char* filename = (char*)malloc(16 * sizeof(char));
    snprintf(filename, 16, "%02d%02d%02d%03d.dat", localTime->tm_hour, localTime->tm_min, localTime->tm_sec, milliseconds);

    return filename;
}

// 写入数据
void writeFile(const char* filename) {
    FILE* file = fopen(filename, "wb");
    if (file == NULL) {
        printf("无法打开文件：%s\n", filename);
        return;
    }

    for (int i = 0; i < 50; ++i) {
        for (int j = 0; j <= 255; ++j) {
            fwrite(&j, sizeof(int), 1, file);
        }
    }

    fclose(file);
}

// 存储线程函数
void* storingThread(void* arg) {
    while (1) {
        pthread_mutex_lock(&mutex);

        if (stopStoring) {
            pthread_mutex_unlock(&mutex);
            break;
        }

        char* filename = generateFilename();
        writeFile(filename);
        free(filename);

        pthread_mutex_unlock(&mutex);

        // 等待文件写入完毕
        struct timespec sleepTime;
        sleepTime.tv_sec = 1;
        sleepTime.tv_nsec = 0;
        nanosleep(&sleepTime, NULL);
    }

    pthread_exit(NULL);
}

int main() {
    pthread_mutex_init(&mutex, NULL);

    for (int i = 0; i < NUM_THREADS; ++i) {
        if (pthread_create(&threads[i], NULL, storingThread, NULL)) {
            printf("错误：无法创建线程\n");
            return -1;
        }
    }

    while (1) {
        // 按键交互
        char key;
        scanf(" %c", &key);

        pthread_mutex_lock(&mutex);

        if (key == 'a') {
            stopStoring = 0;
            printf("开始存储\n");
        } else if (key == 'b') {
            stopStoring = 1;
            printf("停止存储\n");
        }

        pthread_mutex_unlock(&mutex);
    }

    // 等待所有线程结束
    for (int i = 0; i < NUM_THREADS; ++i) {
        pthread_join(threads[i], NULL);
    }

    pthread_mutex_destroy(&mutex);

    return 0;
}
