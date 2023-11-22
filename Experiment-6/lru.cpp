#include <stdio.h>
#include <stdlib.h>

int main()
{
    int numFrames, numPages, pageFaults = 0;

    printf("Enter the number of frames: ");
    scanf("%d", &numFrames);

    printf("Enter the number of reference strings: ");
    scanf("%d", &numPages);

    int *frames = (int *)malloc(numFrames * sizeof(int));
    int *pages = (int *)malloc(numPages * sizeof(int));
    int *pageOrder = (int *)malloc(numFrames * sizeof(int));

    if (frames == NULL || pages == NULL || pageOrder == NULL)
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
        frames[i] = -1;   // Initialize frames to -1 (empty)
        pageOrder[i] = 0; // Initialize page order for each frame
    }

    printf("\nLRU Page Replacement Steps:\n");

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
                // Update page order for the page in the frame
                pageOrder[j] = i + 1;
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
            int replaceIndex = 0;
            int leastRecent = pageOrder[0];

            // Find the page in a frame that was least recently used
            for (int j = 1; j < numFrames; j++)
            {
                if (pageOrder[j] < leastRecent)
                {
                    leastRecent = pageOrder[j];
                    replaceIndex = j;
                }
            }

            // Replace the least recently used page with the new page
            frames[replaceIndex] = page;
            pageOrder[replaceIndex] = i + 1;
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
    free(pageOrder);

    return 0;
}
