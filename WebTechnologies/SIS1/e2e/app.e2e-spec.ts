import { SIS1Page } from './app.po';

describe('sis1 App', () => {
  let page: SIS1Page;

  beforeEach(() => {
    page = new SIS1Page();
  });

  it('should display message saying app works', () => {
    page.navigateTo();
    expect(page.getParagraphText()).toEqual('app works!');
  });
});
