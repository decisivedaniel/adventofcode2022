
namespace AreaChecking
{
    public class ElfArea
    {
        public int leftBound { get; set; }
        public int rightBound { get; set; }

        public ElfArea(string input)
        {
            if(input.Length == 3)
            {
                leftBound = int.Parse(input[0].ToString());
                rightBound = int.Parse(input[2].ToString());
            } 
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
            
        }
    }
    //mcs areaChecking.cs
    //mono areaChecking.exe
}