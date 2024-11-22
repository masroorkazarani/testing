#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX_SEQ 5         // Maximum sequence number
#define WINDOW_SIZE 3     // Size of the window

// Frame structure
struct Frame {
    int seq_no;
    bool is_sent;
    bool is_acked;
};

// Initialize frames
void initialize_frames(struct Frame frames[], int count) {
    for (int i = 0; i < count; i++) {
        frames[i].seq_no = i;
        frames[i].is_sent = false;
        frames[i].is_acked = false;
    }
}

// Simulate sending a frame
void send_frame(struct Frame *frame) {
    printf("Sending frame: %d\n", frame->seq_no);
    frame->is_sent = true;
}

// Simulate receiving an acknowledgment (randomly simulate ack/no-ack)
bool receive_ack() {
    return rand() % 2;
}

// Selective Repeat Sliding Window Protocol
void selective_repeat() {
    struct Frame frames[MAX_SEQ + 1];
    initialize_frames(frames, MAX_SEQ + 1);

    int base = 0;           // Base of the window
    int next_seq = 0;       // Next frame to send

    while (base <= MAX_SEQ) {
        // Send frames within the window
        while (next_seq < base + WINDOW_SIZE && next_seq <= MAX_SEQ) {
            if (!frames[next_seq].is_sent) {
                send_frame(&frames[next_seq]);
            }
            next_seq++;
        }

        // Check acknowledgments for each frame in the window
        for (int i = base; i < next_seq; i++) {
            if (frames[i].is_sent && !frames[i].is_acked) {
                while (!frames[i].is_acked) {  // Retry until ACK is received
                    if (receive_ack()) {
                        printf("Acknowledgment received for frame: %d\n", frames[i].seq_no);
                        frames[i].is_acked = true;
                    } else {
                        printf("No acknowledgment for frame: %d, resending...\n", frames[i].seq_no);
                        send_frame(&frames[i]);
                    }
                }
            }
        }

        // Slide the window if the base frame is acknowledged
        while (frames[base].is_acked && base <= MAX_SEQ) {
            base++;
        }
    }
}

int main() {
    srand(time(NULL));  // Seed the random number generator with the current time
    selective_repeat();
    return 0;
}
