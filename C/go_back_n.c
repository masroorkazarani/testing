#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define WINDOW_SIZE 3
#define MAX_SEQ 7

// Frame structure
struct Frame
{
    int seq_no;
    bool is_sent;
};

// Initialize frames
void initialize_frames(struct Frame frames[], int count)
{
    for (int i = 0; i < count; i++)
    {
        frames[i].seq_no = i;
        frames[i].is_sent = false;
    }
}

// Simulate sending a frame
void send_frame(struct Frame *frame)
{
    printf("Sending frame: %d\n", frame->seq_no);
    frame->is_sent = true;
}

// Simulate receiving an acknowledgment (randomly simulate ack/no-ack)
bool receive_ack()
{
    return rand() % 2;
}

// Go-Back-N Sliding Window Protocol
void go_back_n()
{
    struct Frame frames[MAX_SEQ + 1];
    initialize_frames(frames, MAX_SEQ + 1);

    int base = 0;     // Base of the window
    int next_seq = 0; // Next frame to send

    while (base < MAX_SEQ)
    {
        // Send frames within the window
        while (next_seq < base + WINDOW_SIZE && next_seq <= MAX_SEQ)
        {
            send_frame(&frames[next_seq]);
            next_seq++;
        }

        // Simulate acknowledgment
        bool ack_received = true;
        for (int i = base; i < next_seq; i++)
        {
            if (frames[i].is_sent)
            {
                if (receive_ack())
                {
                    printf("Acknowledgment received for frame: %d\n", frames[i].seq_no);
                    base++;
                }
                else
                {
                    printf("No acknowledgment for frame: %d. Resending window...\n", frames[i].seq_no);
                    ack_received = false;
                    break;
                }
            }
        }

        // If acknowledgment not received, resend the entire window
        if (!ack_received)
        {
            for (int i = base; i < next_seq; i++)
            {
                send_frame(&frames[i]);
            }
        }
    }
}

int main()
{
    srand(time(0));
    printf("Go-Back-N Sliding Window Protocol Simulation:\n");
    go_back_n();
    return 0;
}
