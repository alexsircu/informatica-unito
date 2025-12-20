#include <stdio.h>

#define MAX 3
#define MAXT 100
#define MAXA 100

int main(void)
{
    typedef struct
    {
        char title[MAXT];
        char author[MAXA];
        int duration;
    } song;

    song songs[MAX];

    for (size_t i = 0; i < MAX; i++)
    {
        printf("Song title: ");
        scanf(" %99[^\n]", songs[i].title); // NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)

        printf("Song author: ");
        scanf(" %99[^\n]", songs[i].author); // NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)

        printf("Song duration: ");
        scanf("%d[^\n]", &songs[i].duration); // NOLINT(clang-analyzer-security.insecureAPI.DeprecatedOrUnsafeBufferHandling)
    }

    for (size_t i = 0; i < MAX; i++)
    {
        printf("Song title is: %s, the author is: %s and the duration is: %d\n", songs[i].title,
               songs[i].author, songs[i].duration);
    }

    return 0;
}
