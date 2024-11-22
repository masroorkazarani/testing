#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>f
#include <time.h>

#define MAX_SEQ 5
#define WINDOW_SIZE 3

struct Frame
{
    int seq_no;
    bool is_sent;
    bool is_acked;
};

void intialize_frames(struct Frame frames[], int count)
{
    for (int i = 0; i < count; i++)
    {
        frames[i].seq_no = i;
        frames[i].is_sent = false;
        frames[i].is_acked = false;
    }
}

void send_frame(struct Frame *frame)
{
    printf("Sending Frame %d\n", frame->seq_no);
    frame->is_sent = true;
}

bool receive_ack()
{
    return rand() % 2;
}

void selectiveRepeat()
{
    struct Frame frames[MAX_SEQ + 1];
    intialize_frames(frames, MAX_SEQ + 1);

    int base = 0;
    int next_seq = 0;

    while (base <= MAX_SEQ)
    {
        // sending
        while (next_seq < base + WINDOW_SIZE && next_seq <= MAX_SEQ)
        {
            if (!frames[next_seq].is_sent)
            {
                send_frame(&frames[next_seq]);
            }
            next_seq++;
        }

        // ack
        for (int i = base; i < base + WINDOW_SIZE && i <= MAX_SEQ; i++)
        {
            if (frames[i].is_sent && !frames[i].is_acked)
            {
                while (!frames[i].is_acked)
                {
                    if (receive_ack())
                    {
                        printf("Successfully Acknowledged Frame %d\n\n", frames[i].seq_no);
                        frames[i].is_acked = true;
                    }
                    else
                    {
                        printf("Failed to Acknowledged Frame %d, Resending\n\n", frames[i].seq_no);
                        send_frame(&frames[i]);
                    }
                }
            }
        }

        // iterate window
        while (frames[base].is_acked && base <= MAX_SEQ)
        {
            base++;
        }
    }
}

int main()
{
    srand(time(NULL));
    selectiveRepeat();
    return 0;
}
