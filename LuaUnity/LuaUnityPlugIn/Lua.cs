using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Runtime.InteropServices;

namespace LuaUnityPlugIn
{
    public class Lua
    {

        // From c++ Dll (unmanaged)
        [DllImport("LuaUnity")]
        public static extern float Load(float a, float b);
    }
}
