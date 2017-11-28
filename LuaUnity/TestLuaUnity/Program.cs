using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;
using System.IO;

namespace TestLuaUnity
{
    class Program
    {
        [DllImport("LuaUnity", EntryPoint = "Load")]
        public static extern float Load(string a);

        static void Main(string[] args)
        {
            Console.WriteLine(Load("c:/Level1.lua"));
        }
    }
}
