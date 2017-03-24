import { Task } from './task';

export class Project {
    Id: string;
    Title: string;
    Description: string;
    AdministratorId: String;
    tasks: Task[];
}