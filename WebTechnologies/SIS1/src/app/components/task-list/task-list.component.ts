import { Component, OnInit } from '@angular/core';
import { Task } from './../../models/task';
import { Project } from './../../models/project';
import { ProjectService } from '../../services/project.service';

@Component({
  selector: 'app-task-list',
  templateUrl: './task-list.component.html',
  styleUrls: ['./task-list.component.scss'],
  providers: [ProjectService]
})
export class TaskListComponent implements OnInit {

  public projects: Project[];
  
  constructor(private projectService: ProjectService) {

    projectService.getProjects().subscribe( 
      (projects) => {
        this.projects = projects['value'] as Project[];
        this.loadTasks();
    }, (err) => {
        console.log(err);
      }
    );
  }

  public loadTasks() {
        for (let i in this.projects) {
          this.projectService.getTasks(this.projects[i]).subscribe(
            (tasks) => {
              this.projects[i].tasks = tasks['value'];
            }
          )
        }
  }

  ngOnInit() {
  }

}
