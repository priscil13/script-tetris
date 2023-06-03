# script-tetris
using System;
using System.Threading;

class Tetris
{
    private const int Width = 10;
    private const int Height = 20;

    private int[,] board = new int[Height, Width];
    private int currentX = Width / 2;
    private int currentY = 0;
    private int[,] currentPiece;
    private ConsoleColor currentColor;

    private int score = 0;

    private Random random = new Random();

    private bool isGameOver = false;

    private void Initialize()
    {
        Console.Title = "Tetris";
        Console.CursorVisible = false;
        Console.SetWindowSize(Width * 2, Height + 2);
        Console.SetBufferSize(Width * 2, Height + 2);

        Console.WriteLine("Welcome to Tetris!");
        Console.WriteLine("Use arrow keys to move the pieces. Press 'Q' to quit.");

        Thread.Sleep(2000);
    }

    private void GeneratePiece()
    {
        int pieceType = random.Next(7);
        switch (pieceType)
        {
            case 0:
                currentPiece = new int[2, 2] { { 1, 1 }, { 1, 1 } };
                currentColor = ConsoleColor.Red;
                break;
            case 1:
                currentPiece = new int[2, 3] { { 1, 1, 1 }, { 0, 1, 0 } };
                currentColor = ConsoleColor.Green;
                break;
            case 2:
                currentPiece = new int[2, 3] { { 1, 1, 0 }, { 0, 1, 1 } };
                currentColor = ConsoleColor.Yellow;
                break;
            case 3:
                currentPiece = new int[2, 3] { { 0, 1, 1 }, { 1, 1, 0 } };
                currentColor = ConsoleColor.Blue;
                break;
            case 4:
                currentPiece = new int[2, 3] { { 1, 1, 1 }, { 0, 0, 1 } };
                currentColor = ConsoleColor.Cyan;
                break;
            case 5:
                currentPiece = new int[3, 2] { { 1, 0 }, { 1, 1 }, { 0, 1 } };
                currentColor = ConsoleColor.Magenta;
                break;
            case 6:
                currentPiece = new int[3, 2] { { 0, 1 }, { 1, 1 }, { 1, 0 } };
                currentColor = ConsoleColor.White;
                break;
        }

        currentX = Width / 2;
        currentY = 0;
    }

    private void DrawBoard()
    {
        Console.SetCursorPosition(0, 0);
        Console.ForegroundColor = ConsoleColor.Gray;

        for (int y = 0; y < Height; y++)
        {
            for (int x = 0; x < Width; x++)
            {
                if (x == 0 || x == Width - 1 || y == Height - 1)
                {
                    Console.Write("#");
                }
                else if (board[y, x] != 0)
                {
                    Console.BackgroundColor = ConsoleColor.DarkGray;
                    Console.ForegroundColor = (ConsoleColor)board[y, x];
                    Console.Write("  ");
                }
                else
                {
                    Console.BackgroundColor = ConsoleColor.Black;
                    Console.Write("  ");
                }
           
