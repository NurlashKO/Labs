using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading;
namespace testing
{
    class Customer {
        
        public string name;
        public int time;

        public Customer(string name, int time) {
            this.name = name;
            this.time = time;
        }

        public void goToBarber(object o) {
            Thread barberThread = (Thread)o;
            Barber.queue.Enqueue(this);
            if (Barber.sleeping) {
                System.Console.WriteLine("{0} : Hey, wake up man.", this.name);
                Barber.toWake();
            } else {
                System.Console.WriteLine("Barber: I am a bit busy right now, please take a sit.");
            }
        }

    }
    class Barber {

        public static Queue<Customer> queue = new Queue<Customer>();
        public static bool sleeping = false;
        private void work(Customer person) {
            System.Console.WriteLine("Barber: Hello Mr/Mrs/Ms {0}", person.name);
            while (person.time > 0) {
                //System.Console.WriteLine("Barber: Working...");
                //System.Console.WriteLine("Barber: Customer: {0}", person.name);
                Thread.Sleep(1000);
                person.time -= 1000;
            }
            System.Console.WriteLine("Barber: Have a nice day {0} !", person.name);
        }

        public static void toWake() {
            sleeping = false;
        }

        public void wakeUp() {
            while (true) {
                if (!sleeping) {
                    while (queue.Count > 0) {
                        work(queue.Dequeue());
                        System.Console.WriteLine("Barber: Please next !");
                    }
                    System.Console.WriteLine("Barber: None is here. Ok. I go to sleep");
                    sleeping = true;
                }
            }
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            Barber barber = new Barber();
            Thread barberThread = new Thread(new ThreadStart(barber.wakeUp));
            barberThread.Start();

            while (true) {
                System.Console.WriteLine("Enter customer name : ");
                string name = Console.ReadLine();
                System.Console.WriteLine("Enter needed time : ");
                int time = Convert.ToInt32(Console.ReadLine());
                System.Console.WriteLine("Customer is coming");
                Customer customer = new Customer(name, time);
                Thread customerThread = new Thread(new ParameterizedThreadStart(customer.goToBarber));
                customerThread.Start(barberThread);
            }
        }
    }
}
