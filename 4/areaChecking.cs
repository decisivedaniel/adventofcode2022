using System;
using System.IO;
using System.Text;

namespace AreaChecking
{
    public class ElfArea
    {
        public int leftBound { get; set; }
        public int rightBound { get; set; }

        public ElfArea(string input)
        {
                var bounds = input.Split('-');
                leftBound = int.Parse(bounds[0]);
                rightBound = int.Parse(bounds[1]);
        }

        public bool Contains(ElfArea other)
        {
            return (leftBound <= other.leftBound && rightBound >= other.rightBound);
        }



        public string Print()
        {
            return "Elf has " + leftBound + " - " + rightBound;
        }
    }

    public class Program
    {
        static void Main(string[] args)
        {
            int fullyContainPairs = 0;
            string[] lines = System.IO.File.ReadAllLines(@"./input.txt");
            foreach (string line in lines)
            {
                string[] elfs = line.Split(',');
                var leftElf = new ElfArea(elfs[0]);
                var rightElf = new ElfArea(elfs[1]);
                if (leftElf.Contains(rightElf) || rightElf.Contains(leftElf))
                {
                    fullyContainPairs++;
                }
            }

            System.Console.WriteLine(fullyContainPairs);
        }
    }
    //mcs areaChecking.cs
    //mono areaChecking.exe
}