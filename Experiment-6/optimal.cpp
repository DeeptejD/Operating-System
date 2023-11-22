#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numFrames, numPages, pageFaults = 0, pageHits = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of reference strings: ");
    scanf("%d", &numPages);

    int *frames = (int *)malloc(numFrames * sizeof(int));
    int *pages = (int *)malloc(numPages * sizeof(int));
    int *nextUse = (int *)malloc(numFrames * sizeof(int));

    if (frames == NULL || pages == NULL || nextUse == NULL)
    {
        printf("Memory allocation error\n");
        return 1;
    }

    printf("Enter the reference string: ");
    for (int i = 0; i < numPages; i++)
    {
        scanf("%d", &pages[i]);
    }

    for (int i = 0; i < numFrames; i++)
    {
        frames[i] = -1; // Initialize frames to -1 (empty)
        nextUse[i] = 0; // Initialize next use for each frame
    }

    printf("\nOptimal Page Replacement Steps:\n");

    for (int i = 0; i < numPages; i++)
    {
        int page = pages[i];
        int pageFound = 0;

        // Check if the page is already in a frame
        for (int j = 0; j < numFrames; j++)
        {
            if (frames[j] == page)
            {
                pageFound = 1;
                pageHits++;
                printf("Page Hit: Page %d -> ", page);
                for (int k = 0; k < numFrames; k++)
                {
                    if (frames[k] == -1)
                    {
                        printf("- ");
                    }
                    else
                    {
                        printf("%d ", frames[k]);
                    }
                }
                printf("\n");
                break;
            }
        }

        if (!pageFound)
        {
            // Page fault, so we need to replace a page
            int replaceIndex = -1;
            int farthestUse = -1;

            // Find the page in a frame that will not be used for the longest time
            for (int j = 0; j < numFrames; j++)
            {
                int nextPageUse = numPages; // Default to the farthest use
                for (int k = i + 1; k < numPages; k++)
                {
                    if (pages[k] == frames[j])
                    {
                        nextPageUse = k;
                        break;
                    }
                }

                if (nextPageUse > farthestUse)
                {
                    farthestUse = nextPageUse;
                    replaceIndex = j;
                }
            }

            // Replace the page in the frame with the new page
            frames[replaceIndex] = page;
            nextUse[replaceIndex] = i + 1;
            pageFaults++;
            printf("Page Fault #%d: Page %d -> ", pageFaults, page);
            for (int j = 0; j < numFrames; j++)
            {
                if (frames[j] == -1)
                {
                    printf("- ");
                }
                else
                {
                    printf("%d ", frames[j]);
                }
            }
            printf("\n");
        }
    }

    printf("\nTotal Page Faults: %d\n", pageFaults);

    free(frames);
    free(pages);
    free(nextUse);

    return 0;
}
