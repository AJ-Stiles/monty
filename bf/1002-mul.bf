,>,                  Read the first digit and store it in the first cell
>,                   Read the second digit and store it in the second cell
[                    Start the loop
    -                  Decrement the second digit
    [->+<]             Move the first digit to the third cell
    >[-<+>]            Move the third cell value back to the first cell
    <-                 Decrement the second cell
]                    End the loop
.                    Print the result

