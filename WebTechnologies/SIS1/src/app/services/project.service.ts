import { Injectable } from '@angular/core';
import { Http, Response } from '@angular/http'

@Injectable()
export class ProjectService {

    constructor(private _http: Http) { }

    getProjects() {
        //return this._http.get('/api/Menu/Menus') - api works fine
        return this._http.get('http://tas.ddnsfree.com:40010/odata/Projects')
            .map((response: Response) => response.json())
            .catch(this._handleError);
    }

    _handleError(err: any) {
        //TODO - Give user a nice error message.
        console.log(err);
        return Observable.throw(err);
    };

}
